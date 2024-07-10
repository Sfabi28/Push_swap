/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fewer_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:53:50 by sfabi             #+#    #+#             */
/*   Updated: 2023/12/13 10:09:13 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	count_rotations(int n, t_list *lst)
{
	int	rot;
	int	prev;

	rot = 0;
	prev = 0;
	while (lst && n - lst->nbr < prev)
	{
		prev = n - lst->nbr;
		lst = lst->next;
		rot++;
	}
	while (lst && n - lst->nbr > prev)
	{
		lst = lst->next;
		rot++;
	}
	if (!lst)
		return (0);
	return (rot);
}

void	control_array(int *rot, t_list **b, int size, int **final_arr)
{
	int	i;
	int	i_min;
	int	min;

	i = 0;
	min = INT_MAX;
	while (i < size)
	{
		if (rot[i] < min)
		{
			i_min = i;
			min = rot[i];
		}
		i++;
	}
	if (size - i_min < i_min)
		while (size - i_min++)
			rrb(b, final_arr);
	else
		while (i_min--)
			rb(b, final_arr);
}

static	int	set_rot(int size_a, int size_b, int i, int r)
{
	int	rot_a;
	int	rot_b;
	int	flag;

	flag = 0;
	if (size_a - r < r)
	{
		rot_a = size_a - r;
		flag--;
	}
	else
		rot_a = r;
	if (size_b - i < i)
	{
		rot_b = size_b - i;
		flag--;
	}
	else
		rot_b = i;
	if ((flag == 0 || flag == -2) && rot_a < rot_b)
		return (rot_b);
	else if ((flag == 0 || flag == -2))
		return (rot_a);
	else
		return (rot_a + rot_b);
}

void	fewer_moves(t_list **a, t_list **b, int size_a, int **final_arr)
{
	int		*rot;
	t_list	*tmp;
	int		i;
	int		r;
	int		size_b;

	size_b = ft_lstsize(*b);
	rot = malloc(size_b * sizeof(int));
	tmp = *b;
	i = -1;
	while (tmp && ++i > -5)
	{
		r = count_rotations(tmp->nbr, *a);
		rot[i] = set_rot(size_a, size_b, i, r);
		tmp = tmp->next;
	}
	control_array(rot, b, size_b, final_arr);
	free(rot);
}
