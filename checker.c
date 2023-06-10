/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:33:02 by abazerou          #+#    #+#             */
/*   Updated: 2023/06/10 11:52:57 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	read_lines(t_list **stack_a, t_list **stack_b)
{
	char	*s;

	while (1)
	{
		s = get_next_line(0);
		if (!s)
			break ;
		check_instructions(s, stack_a, stack_b);
		free(s);
	}
	if (is_stack_sorted_bonus(stack_a) && ft_lstsize(*stack_b) == 0)
		ft_putstr_fd_bonus("OK\n", 1);
	else
		ft_puterror_bonus("KO\n");
}

void	check_instructions(char *s, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(s, "sa") == 1)
		swap(stack_a, 0);
	else if (ft_strcmp(s, "sb") == 1)
		swap(stack_b, 0);
	else if (ft_strcmp(s, "ss") == 1)
		ss(stack_a, stack_b);
	else if (ft_strcmp(s, "pa") == 1)
		push_a(stack_b, stack_a, 0);
	else if (ft_strcmp(s, "pb") == 1)
		push_b(stack_a, stack_b, 0);
	else if (ft_strcmp(s, "ra") == 1)
		rotate_a(stack_a, 0);
	else if (ft_strcmp(s, "rb") == 1)
		rotate_b(stack_b, 0);
	else if (ft_strcmp(s, "rr") == 1)
		rr(stack_a, stack_b);
	else if (ft_strcmp(s, "rra") == 1)
		reverse_rotate_a(stack_a, 0);
	else if (ft_strcmp(s, "rrb") == 1)
		reverse_rotate_b(stack_b, 0);
	else if (ft_strcmp(s, "rrr") == 1)
		rrr(stack_a, stack_b);
	else
		ft_puterror_bonus("Error\n");
}

int	ft_strcmp(char *s, char *ins)
{
	int	i;

	i = 0;
	while (s[i] != '\n' && ins[i])
	{
		if (s[i] == ins[i])
			i++;
		else
			return (0);
	}
	if (s[i] == '\n' && ins[i] == '\0')
		return (1);
	else
		return (0);
}

int	is_stack_sorted_bonus(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *(stack_a);
	while (tmp && tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_v		v;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	v.size = 0;
	v.i = 0;
	if (ac < 2)
		exit(0);
	else
	{
		v.str = get_num_bonus(ac, av);
		v.s = ft_split_bonus(v.str, ' ');
		free(v.str);
		v.size = get_size_bonus(&v);
		v.arr = arr_init_bonus(&v);
		v.arr_cpy = arr_cpy_init_bonus(&v);
		ft_freetab_bonus(&v);
		check_dub_bonus(v.arr_cpy, v.size);
		stack_a = creat_list_bonus(v.arr, v.size);
		index_list_bonus(v.arr_cpy, v.size, &stack_a, &v);
		read_lines(&stack_a, &stack_b);
		ft_free_stack_bonus(&stack_a);
	}
}
