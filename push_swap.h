/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:09:12 by abazerou          #+#    #+#             */
/*   Updated: 2023/06/05 20:08:26 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include "get_next_line.h"

typedef struct t_list
{
	int				data;
	int				index;
	struct t_list	*next;
}t_list;

typedef struct t_v
{
	char	**s;
	char	*str;
	int		*arr;
	int		*arr_cpy;
	int		i;
	int		size;
}t_v;

t_list	*creat_node(void);
t_list	*ft_lstnew(int content, int j);
t_list	*ft_lstlast(t_list	*lst);
t_list	*creat_list(int *arr, int size);
size_t	ft_strlen(const char *s);
void	ft_puterror(char *s);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
char	**ft_split(char const *s, char c);
int		*arr_init(t_v *v);
int		*arr_cpy_init(t_v *v);
int		*check_dub(int *arr, int size);
int		check_num(char *str);
int		*swap_arr(int *arr, int j, int tmp);
int		get_value(char *str, int i, int sign);
int		ft_isdigit(int c);
int		ft_lstsize(t_list *lst);
int		get_mid(t_list **stack_a);
int		get_max(t_list **stack_a);
int		get_min(t_list **stack_a);
int		get_position(int index, t_list **stack_a);
int		is_stack_sorted(t_list **stack_a);
int		find_min(t_list *stack_a);
int		check_middle(t_list *check_v, int pos);
void	swap(t_list **head, char *s);
void	ss(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **head_a, t_list **stack_b, char *s);
void	push_a(t_list **head_b, t_list **stack_a, char *s);
void	rotate_a(t_list **stack_a, char *s);
void	rotate_b(t_list **stack_b, char *s);
void	reverse_rotate_a(t_list **stack_a, char *s);
void	reverse_rotate_b(t_list **stack_b, char *s);
void	rr(t_list **stack_a, t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	index_list(int *arr, int size, t_list **stack_a, t_v *v);
void	sort3(t_list **stack_a);
void	sort3_case0(t_list **stack_a);
void	sort3_case1(t_list **stack_a);
void	sort3_case2(t_list **stack_a);
void	sort4(t_list **stack_a, t_list **stack_b);
void	sort4_helper(t_list **stack_a, t_list **stack_b, int pos, int j);
void	sort5_helper(t_list **stack_a, t_list **stack_b, int pos, int j);
void	sort5(t_list **stack_a, t_list **stack_b);
void	big_sort(t_list **stack_a, t_list **stack_b);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	parse_first_arg(char *str);
void	ft_freetab(t_v *v);
int		get_size(t_v *v);
char	*get_num(int ac, char **av);
void	error_empty(char **av, int i);
// --------------------BONUS---------------------------
t_list	*creat_list_bonus(int *arr, int size);
char	**ft_split_bonus(char const *s, char c);
int		*arr_init_bonus(t_v *v);
int		*arr_cpy_init_bonus(t_v *v);
int		get_size_bonus(t_v *v);
int		*check_dub_bonus(int *arr, int size);
int		is_stack_sorted_bonus(t_list **stack_a);
void	index_list_bonus(int *arr, int size, t_list **stack_a, t_v *v);
void	ft_freetab_bonus(t_v *v);
int		is_stack_sorted_bonus(t_list **stack_a);
void	parse_first_arg_bonus(char **av, int i, int j);
void	ft_puterror_bonus(char *s);
void	ft_putstr_fd_bonus(char *s, int fd);
int		check_num_bonus(char *str);
int		get_value_bonus(char *str, int i, int sign);
char	*get_num_bonus(int ac, char **av);
void	check_instructions(char *s, t_list **stack_a, t_list **stack_b);
void	read_lines(t_list **stack_a, t_list **stack_b);
void	ft_putstr_fd_bonus(char *s, int fd);
int		ft_strcmp(char *s, char *ins);

#endif