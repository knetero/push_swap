/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:48:45 by abazerou          #+#    #+#             */
/*   Updated: 2023/05/29 19:41:23 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	check_middle(t_list *check_v, int pos)
// {
// 	if (check_v->data > check_v->next->data
// 		&& check_v->next->data < check_v->next->next->data)
// 			pos = 1;
// 	return (pos);
// }

void	sort3_case0(t_list **stack_a)
{
	if (is_stack_sorted(stack_a))
		return ;
	swap(stack_a, "sa\n");
	rotate_a(stack_a, "ra\n");
}

void	sort3_case1(t_list **stack_a)
{
	t_list	*tmp;

	tmp = (*stack_a);
	if (tmp->data < tmp->next->next->data)
		swap(stack_a, "sa\n");
	else
		rotate_a(stack_a, "ra\n");
}

void	sort3_case2(t_list **stack_a)
{
	t_list	*tmp;

	tmp = (*stack_a);
	if (tmp->data < tmp->next->data)
		reverse_rotate_a(stack_a, "rra\n");
	else
	{
		swap(stack_a, "sa\n");
		reverse_rotate_a(stack_a, "rra\n");
	}
}
