/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:09:12 by abazerou          #+#    #+#             */
/*   Updated: 2023/05/21 11:38:22 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort5(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp_a;

	push_b(&(*stack_a), &(*stack_b), "pb\n");
	sort4(stack_a, stack_b);
	push_a(&(*stack_b), &(*stack_a), "pa\n");
	tmp_a = (*stack_a);
	while(tmp_a != NULL)
	{
		swap(tmp_a, "sa\n");
		tmp_a = tmp_a->next;
	}
}

void	sort4(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp_a;
	
	push_b(&(*stack_a), &(*stack_b), "pb\n");
	sort3(&(*stack_a));
	push_a(&(*stack_b), &(*stack_a), "pa\n");
	tmp_a = (*stack_a);
	while(tmp_a != NULL)
	{
		swap(tmp_a, "sa\n");
		tmp_a = tmp_a->next;
	}
}

int	find_min(t_list *stack_a)
{
	t_list *trav;
	t_list *check_v;
    int min_value;
	int pos = 0;
	int check = 0;
    
	check_v = stack_a;
    min_value = stack_a->data;
    trav = stack_a->next;
    while(trav != NULL)
    {
        if(trav->data < min_value)
        {
            min_value = trav->data;
			check++;
        }
		pos++;
        trav = trav->next;
		if(check_v->data > check_v->next->data && check_v->next->data < check_v->next->next->data)
			pos = 1;
    }
	if(check == 0)
	{
		pos = 0;
	}
    return(pos);
}

void	sort3(t_list **stack_a)
{
	t_list *tmp1;
	t_list *tmp3;
	t_list *tmp4;
	int pos;
	pos = 0;
	tmp1 = (*stack_a);
	pos = find_min(*stack_a);
	if(pos == 0)
	{
		tmp1 = tmp1->next;
		if(tmp1->data > tmp1->next->data)
		{
			swap(tmp1, "sa\n");
		}
	}
	else if(pos == 1)
	{
		tmp4 = (*stack_a);
		if(tmp4->data > tmp4->next->next->data)
			rotate_a(stack_a, "ra\n");
		else
			swap(tmp4, "sa\n");
	}
	else if(pos == 2)
	{
		reverse_rotate_a(stack_a, "rra\n");
		tmp3 = (*stack_a);
		tmp3 = tmp3->next;
		if(tmp3->data > tmp3->next->data)
		{
			swap(tmp1, "sa\n");
		}
	}
}