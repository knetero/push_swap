/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:35:36 by abazerou          #+#    #+#             */
/*   Updated: 2023/05/30 19:53:34 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack_a(t_list **stack_b, t_list **stack_a)
{
	int	position;
	int	middle;
	int	i;

	while (ft_lstsize(*stack_b) > 0)
	{
		i = 0;
		position = get_position(get_max(stack_b), stack_b);
		middle = get_position(get_mid(stack_b), stack_b);
		if (position <= middle)
		{
			while (i++ < position - 1)
				rotate_b(stack_b, "rb\n");
			push_a(stack_b, stack_a, "pa\n");
		}
		else if (position > middle)
		{
			while (i++ < ft_lstsize(*stack_b) - position + 1)
				reverse_rotate_b(stack_b, "rrb\n");
			push_a(stack_b, stack_a, "pa\n");
		}
	}
}

void	fill_stack_b2(t_list **stack_a, t_list **stack_b, int i, int j)
{
	while (ft_lstsize(*stack_a) > 0)
	{
		if ((*stack_a)->index < i)
		{
			push_b(stack_a, stack_b, "pb\n");
			rotate_b(stack_b, "rb\n");
			i++;
		}
		else if ((*stack_a)->index < (i + j))
		{
			push_b(stack_a, stack_b, "pb\n");
			i++;
		}
		else
			rotate_a(stack_a, "ra\n");
		if (ft_lstsize(*stack_b) > 1)
		{
			if ((*stack_b)->index < (*stack_b)->next->index)
			{
				swap(stack_b, "sb\n");
			}
		}
	}
}

void	fill_stack_b(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		j;

	i = 1;
	j = 15;
	if (ft_lstsize(*stack_a) > 250)
		j = 25;
	fill_stack_b2(stack_a, stack_b, i, j);
}


void	big_sort(t_list **stack_a, t_list **stack_b)
{
	fill_stack_b(stack_a, stack_b);
	fill_stack_a(stack_b, stack_a);
}
