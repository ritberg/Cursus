/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:18:03 by mmakarov          #+#    #+#             */
/*   Updated: 2022/12/29 13:49:22 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*pile_a;
	t_list	*pile_b;

	if (argc <= 1)
		return (0);
	if (!err_checker(argc, argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	pile_b = NULL;
	pile_a = create_pile_a(argc, argv);
	small_sort(&pile_a, &pile_b);
	middle_sort(&pile_a, &pile_b);
	printlist(pile_a); //del

	return (0);
}
