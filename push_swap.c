/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:09:00 by abazerou          #+#    #+#             */
/*   Updated: 2023/05/26 17:21:48 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	str = "";
	i = 1;
	while (i < ac)
	{
		if (ft_strlen(av[i]) == 0)
			ft_puterror("Error!\n");
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
    if(ac < 2)
        ft_puterror("Error: in args!\n");	
    else
	{
		str = get_num(ac, av);
		s = ft_split(str, ' ');
		while(s[size])
			size++;
		if(size == 1)
			exit(0);
		arr = malloc(sizeof(int) * (size));
		arr_cpy = malloc(sizeof(int) * (size));
		if(!arr)
			return(free(arr), 0);
		while(s[i])
		{
			arr[i] = check_num(s[i]);
			i++;
		}
		i = 0;
		while(s[i])
		{
			arr_cpy[i] = arr[i];
			i++;
		}
		check_dub(arr_cpy, i);
		stack_a = creat_list(arr, size);
		index_list (arr_cpy, size, &stack_a);
		// get_min(&stack_a);
		// get_max(&stack_a);
		// get_mid(&stack_a);
		// printf("%d\n", j);
		
		// printf("%d\n", get_mid(&stack_a));
		// printf("%d\n", get_index(get_mid(&stack_a), &stack_a));
		// i = 0;
		// while(size != 0)
		// {
		// 	printf("%d\n", arr_cpy[i++]);
		// 	size--;
		// }
		// if(size == 2)
		// 	swap(stack_a, "sa\n");
		// else if(size == 3)
		// 	sort3(&stack_a);
		// else if(size == 4)
		// 	sort4(&stack_a, &stack_b);
		// else if(size == 5)
		// 	sort5(&stack_a, &stack_b);
		while(stack_a)
		{
			printf("a => %d  || index = %d \n", stack_a->data, stack_a->index);
			stack_a = stack_a->next;
		}
		printf("\n\n");
		while(stack_b)
		{
			printf("b =>%d\n", stack_b->data);
			stack_b = stack_b->next;
		}
	}
}
