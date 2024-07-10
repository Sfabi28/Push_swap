/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 08:50:29 by sfabi             #+#    #+#             */
/*   Updated: 2023/12/12 14:46:19 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
#include "control_mass_a.c"
#include "fewer_moves.c"
#include "ft_atoi.c"
#include "ft_bzero.c"
#include "ft_calloc.c"
#include "ft_lstadd_back.c"
#include "ft_lstadd_front.c"
#include "ft_lstlast.c"
#include "ft_lstsize.c"
#include "ft_putchar_fd.c"
#include "ft_putstr_fd.c"
#include "ft_split.c"
#include "ft_strdup.c"
#include "ft_strlen.c"
#include "ft_substr.c"
#include "utils.c"
#include "push_swap.c"
#include "push.c"
#include "reverse.c"
#include "rotate.c"
#include "swap.c"
#include "build_chunk.c"
#include "check.c"
#include "f_lstclear.c"
#include "f_lstdelone.c"
#include "f_lstnew.c"
#include "control_a.c"
#include "control_b.c"

int	main()
{
	char **argv;
	char **args;
	int		argc;
	int		*nbr;
	int		i;
	t_list	*lst;
	t_list	*moves;
	
	argv = malloc(sizeof(char *) * 5);
	argv[0] = ft_strdup("./a.out");
	argv[1] = ft_strdup("1");
	argv[2] = ft_strdup("5");
	argv[3] = ft_strdup("0");
	argv[4] = ft_strdup("3");
	args = set_args(5, argv);
	argc = set_argc(5, argv);
	if (argc < 2 || check_args(args, argc) < 0)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	nbr = set_nbr(args, argc);
	ft_freesplit(args, argc);
	lst = NULL;
	i = -1;
	while (++i < argc)
		ft_lstadd_back(&lst, f_lstnew(&nbr[i], NULL));
	moves = push_swap(&lst);
	print_moves(moves);
	ft_lstclear(&moves);
	ft_lstclear(&lst);
	free(nbr);
	return (0);
}*/

int	main(int argc, char **argv)
{
	int		*nbr;
	int		i;
	t_list	*lst;
	char	**args;

	if (argc < 2)
		return (0);
	args = set_args(argc, argv);
	argc = set_argc(argc, argv);
	if (check_args(args, argc) < 0)
	{
		write(1, "Error\n", 6);
		ft_freesplit(args, argc);
		return (-1);
	}
	nbr = set_nbr(args, argc);
	ft_freesplit(args, argc);
	lst = NULL;
	i = -1;
	while (++i < argc)
		ft_lstadd_back(&lst, f_lstnew(nbr[i]));
	push_swap(&lst);
	f_lstclear(&lst);
	free(nbr);
	return (0);
}
