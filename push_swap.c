/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:09:00 by abazerou          #+#    #+#             */
/*   Updated: 2023/05/12 12:59:28 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *get_num(int ac, char **av)
{
	char *str = "";
	int i = 1;
	while(i < ac)
	{
		str = ft_strjoin(str, av[i]);
		i++;
		if(!str)
			return(NULL);
		if (i < ac)
			str = ft_strjoin(str, " ");
	}
    str[ft_strlen(str)] = '\0';
	return(str);
}

int check_num(char *str)
{
	int	i;
	int	sign;
	long long	value;
	int degit;

	sign = 1;
	value = 0; 
	degit = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if(str[i + 1] == '-' || str[i + 1] == '+' )
		{
			ft_puterror("Error!\n");
		}
		value = value * 10 + (str[i] - '0');
		degit++;
		i++;
	}
    if(value * sign > 2147483647 || value * sign < -2147483648 || degit == 0)
    {
        ft_puterror("Error!\n");
    }
    return(value * sign);
}

int main(int ac, char **av)
{
	int i = 0;
	char *str;
	char **s;
	int *arr;
	arr = malloc(sizeof(int) * (ac - 1));
    if(ac < 2)
        ft_puterror("Error: in args!\n");	
    else
	{
		str = get_num(ac, av);
		s = ft_split(str, ' ');
		
		// while (s[i])
		// {
    	// 	printf("%s\n", s[i++]);
		// }
		while(s[i])
		{
			arr[i] = check_num(s[i]);
			i++;
		}
		arr[i] = 0;
		i = 0;
		while(arr[i])
		{
			printf("%d\n", arr[i++]);
		}
	}
}
