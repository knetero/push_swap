/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:09:12 by abazerou          #+#    #+#             */
/*   Updated: 2023/05/29 19:21:11 by abazerou         ###   ########.fr       */
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
	if (pos == 1)
	{
		push_b(stack_a, stack_b, "pb\n");
		sort3(stack_a);
		push_a(stack_b, stack_a, "pa\n");
	}
	else if (pos > j)
	{
		while (ft_lstsize((*stack_a)) >= pos)
		{
			reverse_rotate_a(stack_a, "rra\n");
			pos++;
		}
		push_b(stack_a, stack_b, "pb\n");
		sort3(stack_a);
		push_a(stack_b, stack_a, "pa\n");
	}
	else
	{
		swap(stack_a, "sa\n");
		push_b(stack_a, stack_b, "pb\n");
		sort3(stack_a);
		push_a(stack_b, stack_a, "pa\n");
	}
}

int	find_min(t_list *stack_a)
{
	// t_list	*trav;
	// t_list	*check_v;
	// int		min_value;
	// int		pos;
	// int		check;

	// pos = 0;
	// check = 0;
	// check_v = stack_a;
	// min_value = stack_a->data;
	// trav = stack_a->next;
	// while (trav != NULL)
	// {
	// 	if (trav->data < min_value)
	// 	{
	// 		min_value = trav->data;
	// 		check++;
	// 	}
	// 	pos++;
	// 	trav = trav->next;
	// 	pos = check_middle(check_v, pos);
	// }
	// if (check == 0)
	// 	pos = 0;
	// return (pos);
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

