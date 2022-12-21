/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:42:21 by mmakarov          #+#    #+#             */
/*   Updated: 2022/12/21 18:01:22 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Replace this by lst chainee et structure

	pile_a = malloc(sizeof(int) * (argc - 1));
	j = 1;
	while (j < argc)
	{
		pile_a[j - 1] = malloc(sizeof(int) * ft_strlen(argv[j]));
		ft_strcpy(pile_a[j - 1], argv[j]);
		j++;
	}
	new_index(argc, pile_a);
*/

void	err_checker(int argc, char **argv)
{
	int	j;
	int	i;

	if (argc <= 1)
		write(1, "\n", 1);
	j = 1;
	i = 1;
	while (j < argc)
	{
		if (ft_isalpha(argv[j]))
			write(1, "Error\n", 6);
		if (ft_atoi(argv[j]) > 2147483647)
			write(1, "Error\n", 6);
		if (ft_atoi(argv[j]) < -2147483648)
			write(1, "Error\n", 6);
		i = j + 1;
		while (i < argc)
		{
			if (ft_atoi(argv[j]) == ft_atoi(argv[i]))
				write(1, "Error\n", 6);
			i++;
		}
		j++;
	}
}
