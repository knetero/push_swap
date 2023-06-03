/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_instructions_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:44:53 by abazerou          #+#    #+#             */
/*   Updated: 2023/06/02 12:16:04 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_b(t_list **stack_b, char *s)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*tmp3;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	tmp2 = *stack_b;
	while (tmp2->next->next)
	{
		tmp2 = tmp2->next;
	}
	tmp3 = tmp2->next;
	tmp2->next = NULL;
	(*stack_b) = tmp3;
	tmp3->next = tmp;
	ft_putstr_fd_bonus(s, 1);
}

void	reverse_rotate_a(t_list **stack_a, char *s)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*tmp3;

	if (!*stack_a)
		return ;
	tmp = *stack_a;
	tmp2 = *stack_a;
	while (tmp2->next->next != NULL)
	{
		tmp2 = tmp2->next;
	}
	tmp3 = tmp2->next;
	tmp2->next = NULL;
	(*stack_a) = tmp3;
	tmp3->next = tmp;
	ft_putstr_fd_bonus(s, 1);
}

void	rotate_b(t_list **stack_b, char *s)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp2 = *stack_b;
	while (tmp2->next != NULL)
	{
		tmp2 = tmp2->next;
	}
	tmp2->next = tmp;
	tmp->next = NULL;
	ft_putstr_fd_bonus(s, 1);
}

void	rotate_a(t_list **stack_a, char *s)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!*stack_a)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp2 = *stack_a;
	while (tmp2->next != NULL)
	{
		tmp2 = tmp2->next;
	}
	tmp2->next = tmp;
	tmp->next = NULL;
	ft_putstr_fd_bonus(s, 1);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate_a(stack_a, NULL);
	rotate_b(stack_b, NULL);
	ft_putstr_fd_bonus("rr\n", 1);
}
