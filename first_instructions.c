/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:20:51 by abazerou          #+#    #+#             */
/*   Updated: 2023/06/06 16:28:11 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort4_helper(t_list **stack_a, t_list **stack_b, int pos, int j)
{
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

void	push_a(t_list **head_b, t_list **stack_a, char *s)
{
	t_list	*tmp_b;

	if (!*head_b)
		return ;
	tmp_b = *head_b;
	(*head_b) = (*head_b)->next;
	ft_lstadd_front(stack_a, ft_lstnew(tmp_b->data, tmp_b->index));
	free(tmp_b);
	ft_putstr_fd(s, 1);
}

void	push_b(t_list **head_a, t_list **stack_b, char *s)
{
	t_list	*tmp_a;

	if (!*head_a)
		return ;
	tmp_a = *head_a;
	(*head_a) = (*head_a)->next;
	ft_lstadd_front(stack_b, ft_lstnew(tmp_a->data, tmp_a->index));
	ft_putstr_fd(s, 1);
	free(tmp_a);
}

void	swap(t_list **head, char *s)
{
	t_list	*tmp_head;
	int		tmp;
	int		in;

	if ((*head) == NULL || ((*head)->next == NULL))
		return ;
	tmp_head = (*head);
	tmp = (*head)->data;
	in = tmp_head->index;
	tmp_head->data = tmp_head->next->data;
	tmp_head->index = tmp_head->next->index;
	tmp_head->next->index = in;
	tmp_head->next->data = tmp;
	ft_putstr_fd(s, 1);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate_a(stack_a, NULL);
	reverse_rotate_b(stack_b, NULL);
	ft_putstr_fd("rr\n", 1);
}
