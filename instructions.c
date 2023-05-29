/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:20:51 by abazerou          #+#    #+#             */
/*   Updated: 2023/05/29 01:58:22 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list **head_b, t_list **stack_a, char *s)
{
	// t_list	*tmp_a;
	// t_list	*tmp_a;
	t_list	*tmp_b;

	if (!*head_b)
		return ;
	tmp_b = *head_b;
	// tmp_a = *stack_a;
	// (*stack_a) = tmp_b;
	(*head_b) = (*head_b)->next;
	ft_lstadd_front(stack_a, ft_lstnew(tmp_b->data, tmp_b->index));
	ft_putstr_fd(s, 1);
}

void	push_b(t_list **head_a, t_list **stack_b, char *s)
{
	t_list	*tmp_a;
	// t_list	*tmp_b;

	if (!*head_a)
		return ;
	tmp_a = *head_a;
	// tmp_b = *stack_b;
	// (*stack_b) = tmp_a;
	(*head_a) = (*head_a)->next;
	ft_lstadd_front(stack_b, ft_lstnew(tmp_a->data, tmp_a->index));
	ft_putstr_fd(s, 1);
}

void	swap(t_list **head, char *s)
{
	t_list	*tmp_head;
	int	tmp;
	int in;

	if ((*head) == NULL || ((*head)->next == NULL))
		return ;
	tmp_head = (*head);
	// if (head->data > head->next->data)
	// {
		tmp = (*head)->data;
		in = tmp_head->index;
		tmp_head->data = tmp_head->next->data;
		tmp_head->index = tmp_head->next->index;
		tmp_head->next->index = in;
		tmp_head->next->data = tmp;
		ft_putstr_fd(s, 1);
	// }
}
