/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:09:00 by abazerou          #+#    #+#             */
/*   Updated: 2023/05/20 14:18:41 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_b(t_list **stack_b, char *s)
{
	t_list *tmp;
	t_list *tmp2;
	t_list *tmp3;;
	
	if (!*stack_b)
		return ;
	tmp = *stack_b;
	tmp2 = *stack_b;
	while(tmp2->next->next != NULL)
	{
		tmp2 = tmp2->next;
	}
	tmp3 = tmp2->next;
	tmp2->next = NULL;
	(*stack_b) = tmp3;
	tmp3->next = tmp;
	ft_putstr_fd(s, 1);
}

void	reverse_rotate_a(t_list **stack_a, char *s)
{
	t_list *tmp;
	t_list *tmp2;
	t_list *tmp3;;
	
	if (!*stack_a)
		return ;
	tmp = *stack_a;
	tmp2 = *stack_a;
	while(tmp2->next->next != NULL)
	{
		tmp2 = tmp2->next;
	}
	tmp3 = tmp2->next;
	tmp2->next = NULL;
	(*stack_a) = tmp3;
	tmp3->next = tmp;
	ft_putstr_fd(s, 1);
}

void	rotate_b(t_list **stack_b, char *s)
{
	t_list *tmp;
	t_list *tmp2;
	
	if (!*stack_b)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp2 = *stack_b;
	while(tmp2->next != NULL)
	{
		tmp2 = tmp2->next;
	}
	tmp2->next = tmp;
	tmp->next = NULL;
	ft_putstr_fd(s, 1);
}

void	rotate_a(t_list **stack_a, char *s)
{
	t_list *tmp;
	t_list *tmp2;
	
	if (!*stack_a)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp2 = *stack_a;
	while(tmp2->next != NULL)
	{
		tmp2 = tmp2->next;
	}
	tmp2->next = tmp;
	tmp->next = NULL;
	ft_putstr_fd(s, 1);
}

void	push_a(t_list **head_b, t_list **stack_a, char *s)
{
	t_list *tmp_a;
	t_list *tmp_b;
	
	if (!*head_b)
		return ;
	tmp_b = *head_b;
	tmp_a = *stack_a;
	(*stack_a) = tmp_b;
	(*head_b) = (*head_b)->next;
	(*stack_a)->next = tmp_a;
	ft_putstr_fd(s, 1);
}

void push_b(t_list **head_a, t_list **stack_b, char *s)
{
	t_list *tmp_a;
	t_list *tmp_b;
	
	if (!*head_a)
		return ;
	tmp_a = *head_a;
	tmp_b = *stack_b;
	(*stack_b) = tmp_a;
	(*head_a) = (*head_a)->next;
	(*stack_b)->next = tmp_b;
	ft_putstr_fd(s, 1);
}

void	swap(t_list *head, char *s)
{
	int tmp;
	
	if (head == NULL || (head->next == NULL))
		return ;
	if(head->data > head->next->data)
	{
		tmp = head->data;
		head->data = head->next->data;
		head->next->data = tmp;
		ft_putstr_fd(s, 1);
	}
}

t_list *creat_list(int *arr, int size)
{
	t_list *new_node;
	t_list *head = NULL;
	t_list *top = NULL;

	int i = 0;
	while(i < size)
	{
		new_node = malloc(sizeof(t_list));
		if(!new_node)
		{
			free(new_node);
			return(0);
		}
		new_node->data = arr[i++];
		new_node->next = NULL;
		if(head == NULL)
		{
			head = new_node;
			top = new_node;
		}
		else
		{
			top->next = new_node;
			top = new_node;
		}
	}
	return (head);
}

int check_num(char *str)
{
	int	i;
	int	sign;
	long long	value;

	sign = 1;
	value = 0; 
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
		if(str[i] == '\0')
			ft_puterror("Error:the arg is not digit!\n");
	}
	else if (str[i] == '+')
	{
		i++;
		if(str[i] == '\0')
			ft_puterror("Error:the arg is not digit!\n");
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		value = value * 10 + (str[i] - '0');
		i++;
	}
	if(!ft_isdigit(str[i]) && str[i])
		ft_puterror("Error:the arg is not digit!\n");
    if(value * sign > 2147483647 || value * sign < -2147483648)
    {
        ft_puterror("Error1!\n");
    }
    return(value * sign);
}

char *get_num(int ac, char **av)
{
	char *str = "";
	int i = 1;
	while(i < ac)
	{
		if (ft_strlen(av[i]) == 0)
			ft_puterror("Error!\n");
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

int	*check_dub(int *arr, int size)
{
	int i = 0;
    int j = 0; 
	int tmp = 0;

    while (i < size - 1) 
	{
        j = 0;
        while (j < size - 1 - i) 
		{
            if (arr[j] > arr[j + 1])
			{
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
			else if(arr[j] == arr[j + 1])
				ft_puterror("Error: dublicate number found!\n");
            j++;
        }
        i++;
    }
    return (arr);
}

int main(int ac, char **av)
{
	t_list *stack_a;
	t_list *stack_b = NULL;

	int i = 0;
	int size = 0;
	char *str;
	char **s;
	int *arr;
	int *arr_cpy;
    if(ac < 2)
        ft_puterror("Error: in args!\n");	
    else
	{
		str = get_num(ac, av);
		s = ft_split(str, ' ');
		while(s[size])
			size++;
		if(size == 1)
			exit(0);
		arr = malloc(sizeof(int) * (size));
		if(!arr)
			return(free(arr), 0);
		arr_cpy = malloc(sizeof(int) * (size));
		if(!arr)
			return(free(arr), 0);
		while(s[i])
		{
			arr[i] = check_num(s[i]);
			i++;
		}
		i = 0;
		while(i < size)
		{
			arr_cpy[i] = arr[i];
			i++;
		}
		check_dub(arr_cpy, size);
		stack_a = creat_list(arr, size);
		if(size == 2)
			swap(stack_a, "sa\n");
		else if(size == 3)
			sort3(&stack_a);
			
		// swap(stack_b, "sb\n");
		// push_b(&stack_a, &stack_b, "pb\n");
		// push_b(&stack_a, &stack_b, "pb\n");
		// push_b(&stack_a, &stack_b, "pb\n");
		// push_b(&stack_a, &stack_b, "pb\n");
		// push_b(&stack_a, &stack_b, "pb\n");
		// rotate_a(&stack_a, "ra\n");
		// rotate_b(&stack_b, "rb\n");
		// reverse_rotate_a(&stack_a, "rra\n");
		// reverse_rotate_b(&stack_b, "rrb\n");
		while(stack_a)
		{
			printf("a => %d\n", stack_a->data);
			stack_a = stack_a->next;
		}
		printf("\n\n");
		while(stack_b)
		{
			printf("b =>%d\n", stack_b->data);
			stack_b = stack_b->next;
		}
	}
}
