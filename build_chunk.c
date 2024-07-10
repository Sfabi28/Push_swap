/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_chunk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:49:13 by sfabi             #+#    #+#             */
/*   Updated: 2023/12/12 14:28:59 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

static	void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	while (i < size)
	{
		min = i;
		j = i + 1;
		while (j < size)
		{
			if (tab[j] < tab[min])
			{
				min = j;
			}
			j++;
		}
		ft_swap(&tab[i], &tab[min]);
		i++;
	}
}

static int	*list_to_array(t_list *lst, int argc)
{
	int	*r;
	int	i;

	r = malloc(argc * sizeof(int));
	if (!r || !lst)
		return (NULL);
	i = 0;
	while (lst)
	{
		r[i++] = lst->nbr;
		lst = lst->next;
	}
	ft_sort_int_tab(r, argc);
	return (r);
}

void	build_chunk(t_list **a, t_list **b, int argc, int **final_arr)
{
	int		*sorted;
	int		n;
	int		count;

	count = 0;
	sorted = list_to_array(*a, argc);
	n = argc / (2 * ((argc + 325) / 200));
	while (count < argc - 3 && check_order_a(*a) < 0)
	{
		if ((n >= argc || (*a)->nbr < sorted[n]) && ++count)
			pb(a, b, final_arr);
		else if ((*a)->nbr >= sorted[argc - n])
		{
			pb(a, b, final_arr);
			rb(b, final_arr);
		}
		else
			ra(a, final_arr);
		if (count == n)
			n += (argc / (2 * ((argc + 325) / 200)));
	}
	free(sorted);
}
