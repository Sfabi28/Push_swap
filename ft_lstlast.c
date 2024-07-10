/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:39:51 by sfabi             #+#    #+#             */
/*   Updated: 2023/12/12 14:27:47 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	if (lst == NULL)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

/*int main(void)
{
    t_list *begin_list = NULL;
    char    *data[4] = {"56", "2", "3", "46"};
    int i = 0;
    while (i < 4)
    {
        ft_lstadd_front(&begin_list, (void *)data[i]);
        printf("%s\n", (char *)begin_list->content);
        i++;
    }
    printf("%s\n", (char *)ft_lstlast(begin_list)->content);
    return (0);
}*/
