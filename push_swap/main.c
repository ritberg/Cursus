/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:18:03 by mmakarov          #+#    #+#             */
/*   Updated: 2022/12/21 16:59:30 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	j;
	void	**pile_a;

	err_checker(argc, pile_a);
	pile_a = malloc(sizeof(int) * (argc - 1));
	j = 1;
	while (j < argc)
	{
		pile_a[j - 1] = malloc(sizeof(int) * ft_strlen(argv[j]));
		ft_strcpy(pile_a[j - 1], argv[j]);
		j++;
	}
	new_index(argc, pile_a)
	return (0);
}
