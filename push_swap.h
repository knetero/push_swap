/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:09:12 by abazerou          #+#    #+#             */
/*   Updated: 2023/05/26 19:29:16 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>


typedef struct t_list
{
	int				data;
	int				index;
	struct t_list	*next;
}t_list;

size_t	ft_strlen(const char *str);
t_list	*creat_node(t_list *new_node);
void	ft_puterror(char *s);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
int		*check_dub(int *arr, int size);
int		check_num(char *str);
int		*swap_arr(int *arr, int j, int tmp);
int		get_value(char *str, int i, int sign);
int		ft_isdigit(int c);
int		ft_lstsize(t_list *lst);
void	swap(t_list *head, char *s);
void	push_b(t_list **head_a, t_list **stack_b, char *s);
void	push_a(t_list **head_b, t_list **stack_a, char *s);
void	rotate_a(t_list **stack_a, char *s);
void	rotate_b(t_list **stack_b, char *s);
void	reverse_rotate_a(t_list **stack_a, char *s);
void	reverse_rotate_b(t_list **stack_b, char *s);
void	index_list(int *arr, int size, t_list **stack_a);
int		get_mid(t_list **stack_a);
int		get_max(t_list **stack_a);
int		get_min(t_list **stack_a);
int		get_index(int index, t_list **stack_a);
void	sort3(t_list **stack_a);
void	sort4(t_list **stack_a, t_list **stack_b);
void	sort5(t_list **stack_a, t_list **stack_b);
int		find_min(t_list *stack_a);

#endif