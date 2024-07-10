/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:45:49 by sfabi             #+#    #+#             */
/*   Updated: 2023/12/12 14:45:49 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *s)
{
	char	*d;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	d = (char *) malloc(sizeof(char) * len + 1);
	if (d == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

/*int main()
{
	const char	*s = "prova";
	
	printf("%p : %s\n", s, s);
	printf("%p : %s", ft_strdup(s), ft_strdup(s));
	return 0;
}*/
