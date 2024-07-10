/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:31:21 by sfabi             #+#    #+#             */
/*   Updated: 2023/12/13 10:08:42 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_list **lst)
{
	t_list	*tmp;
	t_list	*last;
	t_list	*before_last;

	last = ft_lstlast(*lst);
	before_last = lst_bef_last(*lst);
	tmp = *lst;
	*lst = last;
	(*lst)->next = tmp;
	before_last->next = NULL;
}

void	rotate(t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	ft_lstadd_back(lst, f_lstnew((*lst)->nbr));
	tmp = (*lst)->next;
	f_lstdelone(*lst);
	*lst = tmp;
}

void	swap(t_list **lst)
{
	int	t;

	if (!lst || !(*lst)->next)
		return ;
	t = (*lst)->next->nbr;
	(*lst)->next->nbr = (*lst)->nbr;
	(*lst)->nbr = t;
}

void	push(t_list **to, t_list **from)
{
	t_list	*tmp;

	if (!*from)
		return ;
	tmp = (*from)->next;
	ft_lstadd_front(to, f_lstnew((*from)->nbr));
	if (tmp)
		f_lstdelone(*from);
	else
		f_lstclear(from);
	*from = tmp;
}

void	do_both(t_list **a, t_list **b, int i)
{
	if (i == 1)
	{
		rotate(a);
		rotate(b);
	}
	else if (i == 2)
	{
		reverse(a);
		reverse(b);
	}
	else
	{
		swap(a);
		swap(b);
	}
}
