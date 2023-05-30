/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:09:12 by abazerou          #+#    #+#             */
/*   Updated: 2023/05/30 13:55:08 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort5(t_list **stack_a, t_list **stack_b)
{
	push_b(&(*stack_a), &(*stack_b), "pb\n");
	sort4(stack_a, stack_b);
	push_a(stack_b, stack_a, "pa\n");
	sort4(stack_a, stack_b);
}

void	sort4(t_list **stack_a, t_list **stack_b)
{
	int		pos;
	int		j;

	pos = get_position(get_min(stack_a), stack_a);
	j = ft_lstsize((*stack_a)) / 2;
	sort4_helper(stack_a, stack_b, pos, j);
}

int	find_min(t_list *stack_a)
{
	t_list	*tmp;
	int		min_value;

	tmp = stack_a;
	min_value = stack_a->index;
	while (tmp)
	{
		if (tmp->index < min_value)
			min_value = tmp->index;
		tmp = tmp->next;
	}
	return (get_position(min_value, &stack_a));
}

void	sort3(t_list **stack_a)
{
	int		pos;

	pos = find_min(*stack_a);
	if (pos == 1)
		sort3_case0(stack_a);
	else if (pos == 2)
		sort3_case1(stack_a);
	else if (pos == 3)
		sort3_case2(stack_a);
}
