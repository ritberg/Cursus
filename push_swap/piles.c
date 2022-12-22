/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:21:54 by mmakarov          #+#    #+#             */
/*   Updated: 2022/12/22 15:25:18 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	piles(int argc, char **argv)
{
	int	j;
	long long	a;
	t_list	*pile_a;
	t_list	*pile_b;
	t_list	*new_elem;

	j = argc - 1;
	pile_a = NULL;
	pile_b = NULL;
	while (j >= 1)
	{
		a = ft_atoi(argv[j]);
		new_elem = ft_lstnew_int(a);
		new_elem->next = pile_a;
		pile_a = new_elem;
		j--;
	}
	printlist(pile_a); //del
}
