/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:18:03 by mmakarov          #+#    #+#             */
/*   Updated: 2022/12/23 12:52:11 by mmakarov         ###   ########.fr       */
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
	sort(pile_a, pile_b);

	return (0);
}
