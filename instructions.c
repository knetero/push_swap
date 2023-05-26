/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:20:51 by abazerou          #+#    #+#             */
/*   Updated: 2023/05/26 15:44:32 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list **head_b, t_list **stack_a, char *s)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	if (!*head_b)
		return ;
	tmp_b = *head_b;
	tmp_a = *stack_a;
	(*stack_a) = tmp_b;
	(*head_b) = (*head_b)->next;
	(*stack_a)->next = tmp_a;
	ft_putstr_fd(s, 1);
}

void	push_b(t_list **head_a, t_list **stack_b, char *s)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	if (!*head_a)
		return ;
	tmp_a = *head_a;
	tmp_b = *stack_b;
	(*stack_b) = tmp_a;
	(*head_a) = (*head_a)->next;
	(*stack_b)->next = tmp_b;
	ft_putstr_fd(s, 1);
}

void	swap(t_list *head, char *s)
{
	int	tmp;

	if (head == NULL || (head->next == NULL))
		return ;
	if (head->data > head->next->data)
	{
		tmp = head->data;
		head->data = head->next->data;
		head->next->data = tmp;
		ft_putstr_fd(s, 1);
	}
}
