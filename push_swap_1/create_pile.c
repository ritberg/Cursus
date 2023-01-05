/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:48:11 by mmakarov          #+#    #+#             */
/*   Updated: 2023/01/05 15:23:19 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*from_str(int argc, char **argv)
{
	char		**new_argv;
	long long	a;
	int			j;
	t_list		*pile;
	t_list		*new_elem;

	new_argv = input_as_str(argv);
	j = n_of_n(new_argv) - 1;
	pile = NULL;
	while (j >= 1)
	{
		a = ft_atoi(new_argv[j]);
		new_elem = ft_lstnew_int(a);
		new_elem->next = pile;
		pile = new_elem;
		j--;
	}
	return (pile);
}

t_list	*create_pile(int argc, char **argv)
{
	int			j;
	long long	a;
	t_list		*pile;
	t_list		*new_elem;

	if (argc == 2)
		return (from_str(argc, argv));
	j = argc - 1;
	pile = NULL;
	while (j >= 1)
	{
		a = ft_atoi(argv[j]);
		new_elem = ft_lstnew_int(a);
		new_elem->next = pile;
		pile = new_elem;
		j--; // the first argv[i] is on the top
	}
	//printlist(pile); //del !!!
	return (pile);
}
