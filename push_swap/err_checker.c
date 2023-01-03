/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:42:21 by mmakarov          #+#    #+#             */
/*   Updated: 2023/01/03 19:35:01 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**str_of_nbrs(int argc, char **argv)
{
	char	**a;

	if (argc == 2)
	{
		a = ft_split(argv[1], ' ');
		if (a == NULL)
			return (NULL);
		return (a);
	}
	return (argv);
}

int	err_checker(int argc, char **argv)
{
	int	j;
	int	i;

	j = 1;
	if (argv == NULL)   //??
		return (0);      // ??
	str_of_nbrs(argc, argv);
	while (j < argc)
	{
		if (!ft_isdigit(argv[j])) //autres char non autorises non plus
			return (0);
		if (ft_atoi(argv[j]) > 2147483647 || ft_atoi(argv[j]) < -2147483648)
			return (0);
		i = j + 1;
		while (i < argc)
		{
			if (ft_atoi(argv[j]) == ft_atoi(argv[i]))
				return (0);
			i++;
		}
		j++;		
	}
	return (1);
}
