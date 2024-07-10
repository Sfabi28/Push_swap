/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:48:16 by sfabi             #+#    #+#             */
/*   Updated: 2023/12/12 14:26:58 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a, int **final_arr)
{
	int	t;

	if (!a || !(*a)->next)
		return ;
	t = (*a)->next->nbr;
	(*a)->next->nbr = (*a)->nbr;
	(*a)->nbr = t;
	**final_arr = 5;
	(*final_arr)++;
}

void	sb(t_list **b, int **final_arr)
{
	int	t;

	if (!b || !(*b)->next)
		return ;
	t = (*b)->next->nbr;
	(*b)->next->nbr = (*b)->nbr;
	(*b)->nbr = t;
	**final_arr = 6;
	(*final_arr)++;
}
