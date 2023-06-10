/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:09:00 by abazerou          #+#    #+#             */
/*   Updated: 2023/06/10 11:38:14 by abazerou         ###   ########.fr       */
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
	while (tmp && tmp->next)
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
		new_node = creat_node();
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

	str = ft_strdup("");
	i = 1;
	j = 0;
	while (i < ac)
	{
		error_empty(av, i);
		while (av[i][j] == 32)
		{
			j++;
			if (av[i][j] == '\0')
				ft_puterror("Error:the arg is not digit!\n");
		}
		str = ft_strjoin(str, av[i]);
		if (!str)
			return (NULL);
		i++;
		if (i < ac)
			str = ft_strjoin(str, " ");
	}
	str[ft_strlen(str)] = '\0';
	return (str);
}

int	main(int ac, char **av)
{
	t_v		v;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	v.size = 0;
	if (ac < 2)
		exit(0);
	else
	{
		v.str = get_num(ac, av);
		v.s = ft_split(v.str, ' ');
		free(v.str);
		v.size = get_size(&v);
		v.arr = arr_init(&v);
		v.arr_cpy = arr_cpy_init(&v);
		ft_freetab(&v);
		check_dub(v.arr_cpy, v.size);
		stack_a = creat_list(v.arr, v.size);
		index_list (v.arr_cpy, v.size, &stack_a, &v);
		if (is_stack_sorted(&stack_a))
			exit(0);
		sort_stack (&stack_a, &stack_b, v.size);
		ft_free_stack(&stack_a);
	}
}
