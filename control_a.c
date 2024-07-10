/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:45:45 by sfabi             #+#    #+#             */
/*   Updated: 2023/12/12 14:28:41 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	conditions_a(int n, t_list *lst)
{
	t_list	*last;

	last = ft_lstlast(lst);
	if ((lst->nbr >= n && last->nbr <= n)
		|| (lst->nbr <= last->nbr && n <= lst->nbr))
		return (0);
	return (1);
}

static	int	min_lst(t_list *lst, t_list	*tmp)
{
	int	min;
	int	i;

	min = INT_MAX;
	while (lst)
	{
		if (min > lst->nbr)
			min = lst->nbr;
		lst = lst->next;
	}
	i = 0;
	while (tmp->nbr != min)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

static	int	count_rot_a(int n, t_list *a)
{
	int		i;
	t_list	*tmp;
	t_list	*lst;

	i = 0;
	lst = NULL;
	lst_copy(&lst, a);
	while (lst && conditions_a(n, lst))
	{
		ft_lstadd_back(&lst, f_lstnew(lst->nbr));
		tmp = lst->next;
		f_lstdelone(lst);
		lst = tmp;
		i++;
	}
	f_lstclear(&lst);
	return (i);
}

void	control_rotate_a(t_list **a, t_list **b, int **final_arr)
{
	int		rot;
	short	sign;
	int		i;
	int		size;

	size = ft_lstsize(*a);
	if (b && *b)
		rot = count_rot_a((*b)->nbr, *a);
	else
		rot = min_lst(*a, *a);
	sign = 1;
	i = rot;
	if (size - rot < rot)
	{
		sign = -1;
		i = size - rot;
	}
	while (i-- > 0)
	{
		if (sign < 0)
			rra(a, final_arr);
		else
			ra(a, final_arr);
	}
}
