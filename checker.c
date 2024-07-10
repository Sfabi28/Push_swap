/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:04:53 by sfabi             #+#    #+#             */
/*   Updated: 2023/12/13 10:08:59 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	do_move(t_list **a, t_list **b, char *move)
{
	if (!ft_strncmp(move, "rra\0", 4))
		reverse(a);
	else if (!ft_strncmp(move, "rrb\0", 4))
		reverse(b);
	else if (!ft_strncmp(move, "ra\0", 3))
		rotate(a);
	else if (!ft_strncmp(move, "rb\0", 3))
		rotate(b);
	else if (!ft_strncmp(move, "pa\0", 3))
		push(a, b);
	else if (!ft_strncmp(move, "pb\0", 3))
		push(b, a);
	else if (!ft_strncmp(move, "sa\0", 3))
		swap(a);
	else if (!ft_strncmp(move, "sb\0", 3))
		swap(b);
	else if (!ft_strncmp(move, "rr\0", 3))
		do_both(a, b, 1);
	else if (!ft_strncmp(move, "rrr\0", 4))
		do_both(a, b, 2);
	else if (!ft_strncmp(move, "ss\0", 3))
		do_both(a, b, 3);
	else
		return (-1);
	return (0);
}

static	int	read_from_stdin(t_list **a, t_list **b)
{
	int		bytes_read;
	char	c;
	char	*buffer;
	int		res;

	bytes_read = -1;
	buffer = ft_calloc(4, 1);
	if (!buffer)
		return (-1);
	while (++bytes_read < 5)
	{
		if (read(0, &c, 1) == 1)
		{
			if (c == '\n' || c == '\0')
				break ;
			buffer[bytes_read] = c;
		}
		else
			break ;
	}
	res = 10;
	if (bytes_read)
		res = do_move(a, b, buffer);
	free(buffer);
	return (res);
}

static	int	is_sorted(t_list *lst)
{
	while (lst && lst->next)
	{
		if (lst->nbr < lst->next->nbr)
			lst = lst->next;
		else
			break ;
	}
	if (lst->next)
		return (0);
	return (1);
}

static	void	check_order(t_list **lst)
{
	t_list	*b;
	int		res;

	b = NULL;
	while (1)
	{
		res = read_from_stdin(lst, &b);
		if (res < 0)
		{
			write(2, "Error\n", 6);
			f_lstclear(&b);
			f_lstclear(lst);
			exit(1);
		}
		else if (res == 10)
			break ;
	}
	if (!b && is_sorted(*lst))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	f_lstclear(lst);
}

int	main(int argc, char **argv)
{
	int		*nbr;
	t_list	*lst;
	char	**args;

	if (argc < 2)
		return (0);
	args = set_args(argc, argv);
	argc = set_argc(argc, argv);
	if (check_args(args, argc) < 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	nbr = set_nbr(args, argc);
	ft_freesplit(args, argc);
	lst = NULL;
	while (--argc >= 0)
		ft_lstadd_front(&lst, f_lstnew(nbr[argc]));
	check_order(&lst);
	free(nbr);
	return (0);
}
