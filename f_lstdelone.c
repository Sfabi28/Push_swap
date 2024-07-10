/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lstdelone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:00:53 by sfabi             #+#    #+#             */
/*   Updated: 2023/12/12 14:28:17 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f_lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	lst->nbr = 0;
	free(lst);
	lst = NULL;
}

/*int main(void)
{
    t_list  *a;
    t_list  *b;
    char *strs[4] = {"sndkandlsa", "hfa", "wq", "papa"};
    int i = 1;

    a = ft_lstnew((void *)strs[0]);
    b = a;
    printf("before freeing %s\n", (char *)b->content);
    while (i < 4)
    {
        ft_lstadd_front(&b, (void *)strs[i]);
        a = b->next;
        printf("before freeing %s\n", (char *)b->content);
        i++;
    }
    ft_lstdelone(b, ft_del);
    while (a)
    {
        if (a)
        	printf("after freeing %s\n", (char *)a->content);
        a = a->next;
    }
}*/
