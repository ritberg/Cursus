/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:18:03 by mmakarov          #+#    #+#             */
/*   Updated: 2022/12/29 17:27:58 by mmakarov         ###   ########.fr       */
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
	pile_a = create_pile(argc, argv);
	//small_sort(&pile_a, &pile_b);
	sort_pile_k(pile_a, argc, argv);
	printlist(pile_a); //del
	middle_sort(&pile_a, &pile_b);
	printlist(pile_a); //del

	return (0);
}
