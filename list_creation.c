/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:24:29 by abazerou          #+#    #+#             */
/*   Updated: 2023/06/03 14:21:26 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*creat_list_bonus(int *arr, int size)
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

void	index_list_bonus(int *arr, int size, t_list **stack_a, t_v *v)
{
	t_list	*tmp;
	int		i;
	int		j;

	i = 0;
	j = size;
	tmp = (*stack_a);
	while (tmp != NULL)
	{
		i = 0;
		size = j;
		while (size != 0)
		{
			if (arr[i] == tmp->data)
			{
				tmp->index = i;
			}
			i++;
			size--;
		}
		tmp = tmp->next;
	}
	free(arr);
	free(v->arr);
	free(tmp);
}
