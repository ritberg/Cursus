/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:42:21 by mmakarov          #+#    #+#             */
/*   Updated: 2022/12/21 16:02:59 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err_checker(int argc, char **argv)
{
	int	j;

	if (argc <= 1)
		write(1, "Error\n", 6);
	j = 1;
	while (j < argc)
	{
		if (ft_isalpha(argv[j]))
			write(1, "Error\n", 6);
		if (argv[j] == argv[j + 1])
			write(1, "Error\n", 6);
		if (ft_atoi(argv[j]) > 2147483647)
			write(1, "Error\n", 6);
		if (ft_atoi(argv[j]) < -2147483648)
			write(1, "Error\n", 6);
		j++;
	}
}
