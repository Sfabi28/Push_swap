/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:17:08 by sfabi             #+#    #+#             */
/*   Updated: 2023/12/12 14:27:42 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*tmp;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

/*int main(void)
{
    t_list *begin_list = NULL;

    char    *data[4] = {"1", "2", "3", "3"};
    int i = 0;
    while (i < 4)
    {
        ft_lstadd_front(&begin_list, (void *)data[i]);
        printf("%s\n", (char *)begin_list->content);
        i++;
    }
    printf("%d\n", ft_lstsize(begin_list));
    return (0);
}*/
