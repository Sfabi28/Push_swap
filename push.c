/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:48:07 by sfabi             #+#    #+#             */
/*   Updated: 2023/12/12 14:27:17 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **a, t_list **b, int **final_arr)
{
	t_list	*tmp;

	if (!*b)
		return ;
	tmp = (*b)->next;
	ft_lstadd_front(a, f_lstnew((*b)->nbr));
	if (tmp)
		f_lstdelone(*b);
	else
		f_lstclear(b);
	*b = tmp;
	**final_arr = 7;
	(*final_arr)++;
}

void	pb(t_list **a, t_list **b, int **final_arr)
{
	t_list	*tmp;

	if (!*a)
		return ;
	tmp = (*a)->next;
	ft_lstadd_front(b, f_lstnew((*a)->nbr));
	f_lstdelone(*a);
	*a = tmp;
	**final_arr = 8;
	(*final_arr)++;
}
