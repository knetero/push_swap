/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:09:12 by abazerou          #+#    #+#             */
/*   Updated: 2023/05/20 14:17:18 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_list *stack_a)
{
	t_list *trav;
    int min_value;
	int pos = 1;
    
    min_value = stack_a->data;
    trav = stack_a->next;
    while(trav != NULL)
    {
        if(trav->data < min_value)
        {
            min_value = trav->data;
			pos++;
        }
        trav = trav->next;
    }
    return(pos);
}

void	sort3(t_list **stack_a)
{
	t_list *tmp1;
	t_list *tmp3;
	int pos;
	pos = 0;
	tmp1 = (*stack_a);
	tmp3 = (*stack_a);
	pos = find_min(*stack_a);
	if(pos == 1)
	{
		tmp1 = tmp1->next;
		swap(tmp1, "sa\n");
	}
	else if(pos == 3)
	{
		reverse_rotate_a(&tmp3, "rra\n");
	}
	printf("%d\n", pos);
}