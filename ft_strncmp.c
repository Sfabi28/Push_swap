/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:46:05 by sfabi             #+#    #+#             */
/*   Updated: 2023/12/12 14:46:05 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*b1;
	unsigned char	*b2;

	b1 = (unsigned char *)s1;
	b2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (b1[i] != b2[i] || b1[i] == '\0' || b2[i] == '\0')
			return (b1[i] - b2[i]);
		i++;
	}
	return (0);
}

/*int main()
{
	printf("%d\n", ft_strncmp("ciao", "bohp", 4));
	printf("%d\n", ft_strncmp("ciao", "ciap", 3));
	printf("%d\n", ft_strncmp("ciao", "ciap", 4));
	return 0;
}*/
