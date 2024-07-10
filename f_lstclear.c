/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lstclear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:16:52 by sfabi             #+#    #+#             */
/*   Updated: 2023/12/12 14:28:23 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	ft_del(void *s)
{
	s = NULL;
}*/

void	f_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			f_lstdelone(*lst);
			(*lst) = tmp;
		}
	}
	*lst = NULL;
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
    ft_lstclear(&b, ft_del);
    while (a)
    {
        a = a->next;
        printf("after freeing %s\n", (char *)a->content);
    }
}*/
