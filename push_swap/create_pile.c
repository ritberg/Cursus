/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:48:11 by mmakarov          #+#    #+#             */
/*   Updated: 2022/12/29 16:22:46 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_pile(int argc, char **argv)
{
	int	j;
	long long	a;
	t_list	*pile;
	t_list	*new_elem;

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
	printlist(pile); //del !!!
	return (pile);
}
