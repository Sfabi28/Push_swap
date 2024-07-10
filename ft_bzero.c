/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:24:56 by sfabi             #+#    #+#             */
/*   Updated: 2023/12/12 14:26:09 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bzero(void *in, size_t n)
{
	char	*ptr;
	size_t	prov;

	ptr = (char *)in;
	prov = 0;
	while (prov < n)
	{
		ptr[prov] = '\0';
		prov++;
	}
	return ;
}
/*int main()
{
    char str[101];

    // Utilizza ft_bzero per azzerare i primi 10 byte della stringa str
    ft_bzero(str, 10);

    // Stampa la stringa risultante, che sarà una stringa vuota
    printf("Stringa dopo ft_bzero: \"%s\"\n", str);

    return 0;
}*/
