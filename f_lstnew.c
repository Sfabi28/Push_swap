/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lstnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 08:41:04 by sfabi             #+#    #+#             */
/*   Updated: 2023/12/12 14:28:12 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*f_lstnew(int n)
{
	t_list	*new_element;

	new_element = malloc(sizeof(t_list));
	if (new_element == NULL)
		return (NULL);
	new_element->nbr = n;
	new_element->next = NULL;
	return (new_element);
}

/*int main(void)
{
	char	*data = "prova";
	t_list  *new_element;
	
	new_element = ft_lstnew(data);
	printf("%s\n", (char *)new_element->content);
	return (0);
}*/
