/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:18:03 by mmakarov          #+#    #+#             */
/*   Updated: 2023/01/05 15:43:50 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	s_m_b(t_list *pile_a, t_list *pile_b, int argc, char **argv)
{
	if (ft_lstsize(pile_a) <= 10)
		sm_sort_max_10(&pile_a, &pile_b, MIN_TO_MAX);
	else if (ft_lstsize(pile_a) <= 100)
	{
		sort_pile_k(pile_a, argc, argv);
		middle_sort(&pile_a, &pile_b);
		small_sort(&pile_a, &pile_b, MIN_TO_MAX);
		small_sort_r(&pile_a, &pile_b, MAX_TO_MIN);
	}
	else
	{
		sort_pile_k(pile_a, argc, argv);
		big_sort(&pile_a, &pile_b);
		small_sort(&pile_a, &pile_b, MIN_TO_MAX);
		small_sort_r(&pile_a, &pile_b, MAX_TO_MIN);
	}
}

int	main(int argc, char **argv)
{
	t_list	*pile_a;
	t_list	*pile_b;
	char	**new_argv;
	int	new_argc;

	if (argc <= 1)
		return (0);
	if (!err_input_checker(argc, argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (argc == 2)
	{
		new_argv = input_as_str(argv);
		new_argc = n_of_n(new_argv);
	}
	new_argv = argv;
	new_argc = argc;
	pile_b = NULL;
	pile_a = create_pile(new_argc, new_argv);
	if (!already_sorted(pile_a))
		return (0);
	if (ft_lstsize(pile_a) <= 2)
		if (pile_a->content > pile_a->next->content)
			write(1, "sa\n", 3);
	s_m_b(pile_a, pile_b, new_argc, new_argv);
/*
	if (ft_lstsize(pile_a) <= 10)
		small_sort_max_10(&pile_a, &pile_b, MIN_TO_MAX);
	else if (ft_lstsize(pile_a) <= 100)
	{
		sort_pile_k(pile_a, argc, argv);
		middle_sort(&pile_a, &pile_b);
		small_sort(&pile_a, &pile_b, MIN_TO_MAX); 
		small_sort_r(&pile_a, &pile_b, MAX_TO_MIN);
	}
	else
	{
		sort_pile_k(pile_a, argc, argv);
		big_sort(&pile_a, &pile_b);
		small_sort(&pile_a, &pile_b, MIN_TO_MAX);
		small_sort_r(&pile_a, &pile_b, MAX_TO_MIN);
	}
*/

	//printlist(pile_a); //del
	//printlist(pile_b); //del

	return (0);
}
