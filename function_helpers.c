/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:46:49 by abazerou          #+#    #+#             */
/*   Updated: 2023/06/05 20:57:25 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*creat_node(void)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
	{
		free(new_node);
		return (0);
	}
	return (new_node);
}

void	ft_puterror(char *s)
{
	ft_putstr_fd(s, 1);
	exit(1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	error_empty(char **av, int i)
{
	if (ft_strlen(av[i]) == 0)
		ft_puterror("Error:the arg is not digit!\n");
}

void	sort5_helper(t_list **stack_a, t_list **stack_b, int pos, int j)
{
	if (pos == 1)
	{
		push_b(stack_a, stack_b, "pb\n");
	}
	else if (pos > j)
	{
		while (ft_lstsize((*stack_a)) >= pos)
		{
			reverse_rotate_a(stack_a, "rra\n");
			pos++;
		}
		push_b(stack_a, stack_b, "pb\n");
	}
	else
	{
		swap(stack_a, "sa\n");
		push_b(stack_a, stack_b, "pb\n");
	}
}
