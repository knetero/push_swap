/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_helpers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:24:29 by abazerou          #+#    #+#             */
/*   Updated: 2023/05/30 19:29:46 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_mid(t_list **stack_a)
{
	int	mid_value;

	mid_value = (ft_lstsize(*stack_a) / 2);
	return (mid_value);
}

int	get_max(t_list **stack_a)
{
	t_list	*tmp;
	int		max_value;

	tmp = (*stack_a);
	max_value = (*stack_a)->index;
	while (tmp)
	{
		if (tmp->index > max_value)
			max_value = tmp->index;
		tmp = tmp->next;
	}
	free(tmp);
	return (max_value);
}

int	get_position(int index, t_list **stack_a)
{
	t_list	*tmp;
	int		j;

	j = 1;
	tmp = (*stack_a);
	while (tmp)
	{
		if (index == tmp->index)
			return (j);
		j++;
		tmp = tmp->next;
	}
	free(tmp);
	return (0);
}

int	get_min(t_list **stack_a)
{
	t_list	*tmp;
	int		min_value;

	min_value = (*stack_a)->index;
	tmp = (*stack_a);
	while (tmp)
	{
		if (tmp->index < min_value)
			min_value = tmp->index;
		tmp = tmp->next;
	}
	free(tmp);
	return (min_value);
}

void	index_list(int *arr, int size, t_list **stack_a)
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
	free(tmp);
}
