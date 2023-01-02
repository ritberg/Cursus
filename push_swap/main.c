/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:18:03 by mmakarov          #+#    #+#             */
/*   Updated: 2023/01/02 18:10:47 by mmakarov         ###   ########.fr       */
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
	if (ft_lstsize(pile_a) <= 10)
		small_sort(&pile_a, &pile_b, MIN_TO_MAX);
	else
	{
		sort_pile_k(pile_a, argc, argv);
		//big_sort(&pile_a, &pile_b);
		middle_sort(&pile_a, &pile_b);
		small_sort(&pile_a, &pile_b, MAX_TO_MIN); // min_to_max 
		                         //for the last chunk remaining in A !
	}
	printlist(pile_a); //del

	return (0);
}
