/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:39:44 by abazerou          #+#    #+#             */
/*   Updated: 2023/06/06 17:49:26 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*arr_cpy_init(t_v *v)
{
	v->arr_cpy = malloc(sizeof(int) * (v->size));
	if (!v->arr_cpy)
	{
		free(v->arr_cpy);
		return (NULL);
	}
	while (v->s[v->i])
	{
		v->arr_cpy[v->i] = v->arr[v->i];
		v->i++;
	}
	return (v->arr_cpy);
}

int	*arr_init(t_v *v)
{
	v->arr = malloc(sizeof(int) * (v->size));
	if (!v->arr)
	{
		free(v->arr);
		return (NULL);
	}
	while (v->s[v->i])
	{
		v->arr[v->i] = check_num(v->s[v->i]);
		v->i++;
	}
	v->i = 0;
	return (v->arr);
}

void	ft_free_stack(t_list **stack)
{
	t_list	*tmp;

	tmp = *(stack);
	while (tmp)
	{
		(*stack) = (*stack)->next;
		free(tmp);
		tmp = tmp->next;
	}
}

