/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:09:00 by abazerou          #+#    #+#             */
/*   Updated: 2023/05/29 19:41:33 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*sort_stack(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 2)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			swap(stack_a, "sa\n");
	}
	else if (size == 3)
		sort3(stack_a);
	else if (size == 4)
		sort4(stack_a, stack_b);
	else if (size == 5)
		sort5(stack_a, stack_b);
	else if (size > 5)
		big_sort(stack_a, stack_b);
	return (*stack_a);
}

int	is_stack_sorted(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *(stack_a);
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_list	*creat_list(int *arr, int size)
{
	t_list	*new_node;
	t_list	*head;
	t_list	*top;
	int		i;

	head = NULL;
	top = NULL;
	i = 0;
	while (i < size)
	{
		new_node = creat_node(new_node);
		new_node->data = arr[i++];
		new_node->next = NULL;
		if (head == NULL)
		{
			head = new_node;
			top = new_node;
		}
		else
		{
			top->next = new_node;
			top = new_node;
		}
	}
	return (head);
}

char	*get_num(int ac, char **av)
{
	char	*str;
	int		i;
	int		j;

	str = "";
	i = 1;
	j = 0;
	while (i < ac)
	{
		parse_first_arg(av, i, j);
		while (av[i][j] == 32)
		{
			j++;
			if (av[i][j] == '\0')
				ft_puterror("Error:the arg is not digit!\n");
		}
		str = ft_strjoin(str, av[i]);
		i++;
		if (!str)
			return (NULL);
		if (i < ac)
			str = ft_strjoin(str, " ");
	}
	str[ft_strlen(str)] = '\0';
	return (str);
}

int main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**s;
	char	*str;
	int		*arr;
	int		*arr_cpy;
	int		i;
	int		size;

	stack_b = NULL;
	// system("leaks push_swap > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");

	size = 0;
	i = 0;
	if (ac < 2)
		exit(0);
	else
	{
		str = get_num(ac, av);
		s = ft_split(str, ' ');
		while (s[size])
			size++;
		if (size == 1)
			exit(0);
		arr = malloc(sizeof(int) * (size));
		arr_cpy = malloc(sizeof(int) * (size));
		if (!arr)
			return (free(arr), 0);
		while (s[i])
		{
			arr[i] = check_num(s[i]);
			i++;
		}
		i = 0;
		while (s[i])
		{
			arr_cpy[i] = arr[i];
			i++;
		}
		check_dub(arr_cpy, i);
		stack_a = creat_list(arr, size);
		index_list (arr_cpy, size, &stack_a);
		if (is_stack_sorted(&stack_a))
			exit(0);
		sort_stack (&stack_a, &stack_b, i);

		// push_b(&stack_a, &stack_b, "pa\n");
		// push_b(&stack_a, &stack_b, "pa\n");
		// while (stack_a)
		// {
		// 	printf("a => %d  || index = %d \n", stack_a->data, stack_a->index);
		// 	stack_a = stack_a->next;
		// }
		// printf("\n\n");
		// while (stack_b)
		// {
		// 	printf("b => %d  || index = %d \n", stack_b->data, stack_b->index);
		// 	stack_b = stack_b->next;
		// }
	}
}
