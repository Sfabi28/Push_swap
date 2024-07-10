/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:01:18 by sfabi             #+#    #+#             */
/*   Updated: 2023/12/12 14:27:52 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

/*int		main(void)
{
	char	*first = "prova";
	char	*last = "12345";
	t_list	*begin_list = ft_lstnew(last);

	ft_lstadd_front(&begin_list, (void *)first);
	printf("%s\n", (char *)begin_list->content);
	printf("%s\n", (char *)begin_list->next->content);
	return(0);
}*/
