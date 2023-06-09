/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:41:18 by abazerou          #+#    #+#             */
/*   Updated: 2023/06/02 12:11:42 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_size_bonus(t_v *v)
{
	while (v->s[v->size])
		v->size++;
	return (v->size);
}

int	*swap_arr(int *arr, int j, int tmp)
{
	if (arr[j] > arr[j + 1])
	{
		tmp = arr[j];
		arr[j] = arr[j + 1];
		arr[j + 1] = tmp;
	}
	return (arr);
}

int	*check_dub_bonus(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			arr = swap_arr(arr, j, tmp);
			if (arr[j] == arr[j + 1])
			{
				ft_puterror_bonus("Error: Duplicate number found!\n");
			}
			j++;
		}
		i++;
	}
	return (arr);
}

int	get_value_bonus(char *str, int i, int sign)
{
	long long	value;

	value = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		value = value * 10 + (str[i] - '0');
		i++;
	}
	if (!ft_isdigit(str[i]) && str[i])
		ft_puterror_bonus("Error:the arg is not digit!\n");
	if (value * sign > 2147483647 || value * sign < -2147483648)
		ft_puterror_bonus("Error: Value > INT_MAX or < INT_MIN!\n");
	return (value * sign);
}

int	check_num_bonus(char *str)
{
	long long	value;
	int			i;
	int			sign;

	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
		if (str[i] == '\0')
			ft_puterror_bonus("Error:the arg is not digit!\n");
	}
	else if (str[i] == '+')
	{
		i++;
		if (str[i] == '\0')
			ft_puterror_bonus("Error:the arg is not digit!\n");
	}
	value = get_value_bonus(str, i, sign);
	return (value);
}
