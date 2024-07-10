/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:44:00 by sfabi             #+#    #+#             */
/*   Updated: 2023/12/12 12:07:08 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_rotates(int arr[2])
{
	while (arr[0])
	{
		if (arr[0] > 0)
		{
			write(1, "ra\n", 3);
			arr[0]--;
		}
		else if (arr[0]++ < 0)
			write(1, "rra\n", 4);
	}
	while (arr[1])
	{
		if (arr[1] > 0)
		{
			write(1, "rb\n", 3);
			arr[1]--;
		}
		else if (arr[1]++ < 0)
			write(1, "rrb\n", 4);
	}
}

static void	final_combine(int arr[2])
{
	if (arr[0] < 0 && arr[1] < 0)
	{
		while (arr[0] && arr[1])
		{
			write (1, "rrr\n", 4);
			arr[0]++;
			arr[1]++;
		}
	}
	else if (arr[0] > 0 && arr[1] > 0)
	{
		while (arr[0] && arr[1])
		{
			write (1, "rr\n", 3);
			arr[0]--;
			arr[1]--;
		}
	}
	print_rotates(arr);
}

static void	print_move(int move)
{
	if (move == 5)
		write(1, "sa\n", 3);
	if (move == 6)
		write(1, "sb\n", 3);
	if (move == 7)
		write(1, "pa\n", 3);
	if (move == 8)
		write(1, "pb\n", 3);
}

void	final_print(int *arr)
{
	int	count;
	int	arr_rotate[2];

	count = 0;
	while (arr[count])
	{
		arr_rotate[0] = 0;
		arr_rotate[1] = 0;
		while (arr[count] && arr[count] < 5)
		{
			if (arr[count] == 1)
				arr_rotate[0]++;
			else if (arr[count] == 2)
				arr_rotate[1]++;
			else if (arr[count] == 3)
				arr_rotate[0]--;
			else if (arr[count] == 4)
				arr_rotate[1]--;
			count++;
		}
		final_combine(arr_rotate);
		print_move(arr[count]);
		count++;
	}
}
