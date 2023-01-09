/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:28:43 by mmakarov          #+#    #+#             */
/*   Updated: 2023/01/02 17:04:18 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_list **pile_a, t_list **pile_b)
{
	int	size;
	int	n_of_pb;
	int	key_nbr;
	int	orig_key_nbr;

	size = ft_lstsize(*pile_a);
	orig_key_nbr = size / 8;
	key_nbr = orig_key_nbr;
	n_of_pb = 0;
	while (size > 100 && key_nbr < (8 * orig_key_nbr))
	{
		while (n_of_pb < key_nbr)
		{
			if ((*pile_a)->content <= key_nbr)
			{
				pb(pile_a, pile_b);
				n_of_pb++;
				size--;
			}
			else
				*pile_a = ra_rb(*pile_a, size, 'a');
		}
		key_nbr += orig_key_nbr;
	}
}
