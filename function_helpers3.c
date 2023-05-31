/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:54:43 by abazerou          #+#    #+#             */
/*   Updated: 2023/05/31 17:33:28 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freetab(t_v *v)
{
	v->i = 0;
	while (v->i < v->size)
	{
		free(v->s[v->i++]);
	}
	free(v->s);
}

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*p;

	if (alst)
	{
		if ((*alst) == NULL)
			(*alst) = new;
		else
		{
			p = *alst;
			while (p->next != NULL)
				p = p->next;
			p->next = new;
		}
	}
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (new)
	{
		new->next = *alst;
		*alst = new;
		new = NULL;
	}
}

t_list	*ft_lstnew(int content, int j)
{
	t_list	*element;

	element = (t_list *)malloc(sizeof(t_list));
	if (!element)
		return (NULL);
	element->data = content;
	element->index = j;
	element->next = NULL;
	return (element);
}
