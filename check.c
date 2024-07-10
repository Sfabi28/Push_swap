/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:58:30 by sfabi             #+#    #+#             */
/*   Updated: 2023/12/13 11:46:52 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	check_duplicate(char **arg, int argc, int i)
{
	int	j;
	int	n;

	j = 0;
	n = ft_atoi(arg[i]);
	while (j < argc)
	{
		if (j != i && ft_atoi(arg[j]) == n)
			return (-1);
		j++;
	}
	return (0);
}

int	check_order_a(t_list *a)
{
	int	check;
	int	first;

	first = a->nbr;
	check = 0;
	while (a)
	{
		if ((a->next && a->nbr > a->next->nbr)
			|| (check == 1 && first < a->nbr))
		{
			if (check == 0)
				check = 1;
			else
				return (-1);
		}
		a = a->next;
	}
	return (check);
}

static	int	check_limits(char *s)
{
	long	i;

	i = 0;
	i = ft_atoi(s);
	if (i > INT_MAX || i < INT_MIN)
		return (1);
	return (0);
}

int	check_args(char **arg, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (arg[i][j])
		{
			if ((j == 0 && (arg[i][j] == 43 || arg[i][j] == 45))
				|| (arg[i][j] > 47 && arg[i][j] < 58))
				j++;
			else
				return (-1);
			if (j > 10 && check_limits(arg[i]))
				return (-1);
		}
		if (check_duplicate(arg, argc, i) == -1)
			return (-1);
		i++;
	}
	return (0);
}
