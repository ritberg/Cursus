/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pile_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:48:11 by mmakarov          #+#    #+#             */
/*   Updated: 2022/12/23 12:35:49 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_pile_a(int argc, char **argv)
{
	int	j;
	long long	a;
	t_list	*pile_a;
	t_list	*new_elem;

	j = argc - 1;
	pile_a = NULL;
	while (j >= 1)
	{
		a = ft_atoi(argv[j]);
		new_elem = ft_lstnew_int(a);
		new_elem->next = pile_a;
		pile_a = new_elem;
		j--; // the first argv[i] is on the top
	}
	printlist(pile_a); //del !!!
	return (pile_a);
}
