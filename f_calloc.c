/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_calloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:35:40 by sfabi             #+#    #+#             */
/*   Updated: 2023/12/12 14:25:20 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*f_calloc(size_t nmemb, size_t size)
{
	int	*arr;

	arr = malloc(nmemb * size);
	if (arr == NULL)
		return (arr);
	ft_bzero(arr, (nmemb * size));
	return (arr);
}
