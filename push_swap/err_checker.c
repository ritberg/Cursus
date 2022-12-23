/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:42:21 by mmakarov          #+#    #+#             */
/*   Updated: 2022/12/23 12:16:03 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	err_checker(int argc, char **argv)
{
	int	j;
	int	i;

	j = 1;
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
