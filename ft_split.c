/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:12:20 by sfabi             #+#    #+#             */
/*   Updated: 2023/12/12 14:45:43 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**ft_free(char **s, int a)
{
	while (a >= 0)
	{
		free(s[a]);
		a--;
	}
	free(s);
	return (NULL);
}

static int	count(char const *cs, char c)
{
	int	i;

	i = 0;
	while (cs[i] != c && cs[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	**split2(char const *s, char c, char **str, int a)
{
	int	t;

	while (*s)
	{
		t = count(s, c);
		if (t)
		{
			str[a] = (char *)malloc((t + 1) * sizeof(char));
			if (!str[a])
			{
				ft_free(str, a);
				return (NULL);
			}
			while (*s != c && *s != '\0')
				*str[a]++ = *s++;
			*str[a] = '\0';
			str[a] = str[a] - t;
			a++;
		}
		else
			s++;
	}
	str[a] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	t;

	t = ft_count(s, c);
	str = (char **)malloc((t + 1) * sizeof (char *));
	if (!str)
		return (NULL);
	str = split2(s, c, str, 0);
	return (str);
}
