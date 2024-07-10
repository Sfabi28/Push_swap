/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:24:30 by sfabi             #+#    #+#             */
/*   Updated: 2023/12/12 14:46:41 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**set_args(int argc, char **argv)
{
	int		i;
	char	**args;

	if (argc == 2)
		return (ft_split(argv[1], ' '));
	args = malloc(argc * sizeof(char *));
	if (!args)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		args[i] = ft_strdup(argv[i + 1]);
		i++;
	}
	args[argc - 1] = NULL;
	return (args);
}

int	set_argc(int argc, char **argv)
{
	if (argc != 2)
		return (argc - 1);
	return (ft_count(argv[1], ' '));
}

int	*set_nbr(char **args, int argc)
{
	int	*nbr;
	int	i;

	nbr = malloc(sizeof(int) * (argc + 1));
	if (!nbr)
		return (NULL);
	i = 0;
	while (i < argc)
	{
		nbr[i] = ft_atoi(args[i]);
		i++;
	}
	nbr[argc] = -1;
	return (nbr);
}

void	ft_freesplit(char **array, int size)
{
	int	i;

	if (array == NULL)
		return ;
	i = 0;
	while (i < size)
	{
		if (array[i] != NULL)
		{
			free(array[i]);
			array[i] = NULL;
		}
		i++;
	}
	free(array);
}
