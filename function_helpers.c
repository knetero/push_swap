/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:46:49 by abazerou          #+#    #+#             */
/*   Updated: 2023/05/30 19:56:43 by abazerou         ###   ########.fr       */
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

char	*ft_strdup(const char *s1)
{
	char	*p;
	char	*str;
	int		i;

	str = (char *)s1;
	i = 0;
	p = (char *)malloc(ft_strlen(str) * sizeof(char) + 1);
	if (!p)
		return (NULL);
	while (*str)
	{
		p[i] = *str;
		str++;
		i++;
	}
	p[i] = '\0';
	return (p);
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

void	parse_first_arg(char **av, int i, int j)
{
	if (ft_strlen(av[i]) == 0)
		ft_puterror("Error!\n");
	while (av[1][j])
	{
		if (!ft_isdigit(av[1][j]))
		{
			if (!ft_isdigit(av[1][j + 1]))
				ft_puterror("Error:the arg is not digit!\n");
			if ((av[1][j] == '-' || av[1][j] == '+'))
				return ;
			ft_puterror("Error:the arg is not digit!\n");
		}
		j++;
	}
	j = 0;
}
