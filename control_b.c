/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 08:54:41 by sfabi             #+#    #+#             */
/*   Updated: 2023/12/12 14:28:34 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	conditions_b(int n, t_list *lst)
{
	t_list	*last;

	last = ft_lstlast(lst);
	if (ft_lstsize(lst) == 2 && n <= lst->nbr && n >= last->nbr)
		return (1);
	if ((lst->nbr <= n && last->nbr >= n)
		|| (lst->nbr >= last->nbr && n >= lst->nbr)
		|| (n >= lst->nbr && lst->nbr >= last->nbr
			&& lst->nbr >= lst->next->nbr)
		|| (n <= last->nbr && lst->nbr >= last->nbr
			&& lst->nbr >= lst->next->nbr))
		return (0);
	return (1);
}

static	int	count_rot_b(int n, t_list *b)
{
	int		i;
	t_list	*tmp;
	t_list	*lst;

	i = 0;
	lst = NULL;
	lst_copy(&lst, b);
	while (lst && conditions_b(n, lst))
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

void	control_rotate_b(t_list **a, t_list **b, int **final_arr)
{
	int		rot;
	short	sign;
	int		i;
	int		size;

	if (!b || !*b)
		return ;
	size = ft_lstsize(*b);
	if (size < 2)
		return ;
	rot = count_rot_b((*a)->nbr, *b);
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
			rrb(b, final_arr);
		else
			rb(b, final_arr);
	}
}
