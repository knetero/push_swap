/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_helpers2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:49:55 by abazerou          #+#    #+#             */
/*   Updated: 2023/06/06 16:16:40 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(char *s)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *)malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!p)
		return (NULL);
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a, 0);
	swap(stack_b, 0);
	ft_putstr_fd("ss\n", 1);
}
