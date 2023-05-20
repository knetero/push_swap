/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:09:12 by abazerou          #+#    #+#             */
/*   Updated: 2023/05/20 14:11:07 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>


typedef struct t_list{
    int data;
    struct t_list *next;
}t_list;

void	ft_puterror(char *s);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
int	    ft_isdigit(int c);
void	swap(t_list *head, char *s);
void    push_b(t_list **head_a, t_list **stack_b, char *s);
void	push_a(t_list **head_b, t_list **stack_a, char *s);
void	rotate_a(t_list **stack_a, char *s);
void	rotate_b(t_list **stack_b, char *s);
void	reverse_rotate_a(t_list **stack_a, char *s);
void	reverse_rotate_b(t_list **stack_b, char *s);
void	sort3(t_list **stack_a);
int	find_min(t_list *stack_a);

#endif