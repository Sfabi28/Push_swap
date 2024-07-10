/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:02:57 by sfabi             #+#    #+#             */
/*   Updated: 2023/12/12 14:27:32 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_smart(t_list **a, int **final_arr)
{
	t_list			*b;

	b = NULL;
	while (check_order_a(*a) < 0)
	{
		if ((*a)->nbr > (*a)->next->nbr)
			sa(a, final_arr);
		if (check_order_a(*a) < 0)
		{
			control_rotate_b(a, &b, final_arr);
			pb(a, &b, final_arr);
		}
	}
	while (b || check_order_a(*a))
	{
		control_rotate_a(a, &b, final_arr);
		if (b)
			pa(a, &b, final_arr);
	}
}

void	push_swap_massive(t_list **a, int size, int **final_arr)
{
	t_list	*b;

	b = NULL;
	build_chunk(a, &b, size, final_arr);
	if (check_order_a(*a) < 0)
		sa(a, final_arr);
	while (b || check_order_a(*a))
	{
		control_mass_a(a, &b, final_arr);
		if (b)
			pa(a, &b, final_arr);
	}
}

static	void	set_arr(int **arr)
{
	(*arr)--;
	while (**arr)
		(*arr)--;
	(*arr)++;
}

void	push_swap(t_list **a)
{
	int	size;
	int	*final_arr;

	final_arr = f_calloc(50000, sizeof(int));
	if (!final_arr)
		return ;
	final_arr++;
	size = ft_lstsize(*a);
	if (size < 19)
		push_swap_smart(a, &final_arr);
	else
		push_swap_massive(a, size, &final_arr);
	set_arr(&final_arr);
	final_print(final_arr);
	final_arr--;
	free(final_arr);
}
