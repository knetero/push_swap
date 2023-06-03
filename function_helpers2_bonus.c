/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_helpers2_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:49:55 by abazerou          #+#    #+#             */
/*   Updated: 2023/06/03 12:49:17 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*get_num_bonus(int ac, char **av)
{
	char	*str;
	int		i;
	int		j;

	str = ft_strdup("");
	i = 1;
	j = 0;
	while (i < ac)
	{
		parse_first_arg_bonus(av, i, j);
		while (av[i][j] == 32)
		{
			j++;
			if (av[i][j] == '\0')
				ft_puterror_bonus("Error:the arg is not digit!\n");
		}
		str = ft_strjoin(str, av[i]);
		if (!str)
			return (NULL);
		i++;
		if (i < ac)
			str = ft_strjoin(str, " ");
	}
	str[ft_strlen(str)] = '\0';
	return (str);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a, NULL);
	swap(stack_b, NULL);
	ft_putstr_fd_bonus("ss\n", 1);
}
