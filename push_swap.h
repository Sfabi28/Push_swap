/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:23:54 by sfabi             #+#    #+#             */
/*   Updated: 2023/12/12 14:46:29 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <stddef.h> 
# include <unistd.h>
# include <stdio.h>

typedef struct i_list
{
	int				nbr;
	struct i_list	*next;
}			t_list;

void	pa(t_list **a, t_list **b, int **final_arr);
void	pb(t_list **a, t_list **b, int **final_arr);
void	rrb(t_list **b, int **final_arr);
void	rra(t_list **a, int **final_arr);
void	rb(t_list **b, int **final_arr);
void	ra(t_list **a, int **final_arr);
void	sb(t_list **b, int **final_arr);
void	sa(t_list **a, int **final_arr);
int		check_order_a(t_list *a);
int		check_args(char **arg, int argc);
void	push_swap(t_list **a);
void	control_rotate_a(t_list **a, t_list **b, int **final_arr);
void	control_rotate_b(t_list **a, t_list **b, int **final_arr);
void	f_lstclear(t_list **lst);
void	f_lstdelone(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*f_lstnew(int n);
long	ft_atoi(const char *str);
int		ft_lstsize(t_list *lst);
void	lst_copy(t_list **copy, t_list *lst);
void	build_chunk(t_list **a, t_list **b, int argc, int **final_arr);
void	control_mass_a(t_list **a, t_list **b, int **final_arr);
void	fewer_moves(t_list **a, t_list **b, int size_a, int **final_arr);
void	ft_bzero(void *in, size_t n);
int		*f_calloc(size_t nmemb, size_t size);
void	*ft_calloc(size_t nmemb, size_t size);
void	final_print(int *arr);
void	*ft_calloc(size_t nitems, size_t size);
void	ft_freesplit(char **array, int size);
int		*set_nbr(char **args, int argc);
int		set_argc(int argc, char **argv);
char	**set_args(int argc, char **argv);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
size_t	ft_count(char const *s, char c);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	reverse(t_list **lst);
void	rotate(t_list **lst);
void	swap(t_list **lst);
void	push(t_list **to, t_list **from);
void	do_both(t_list **a, t_list **b, int i);
t_list	*lst_bef_last(t_list *lst);

#endif
