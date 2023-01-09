/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:34:18 by mmakarov          #+#    #+#             */
/*   Updated: 2023/01/02 18:07:43 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	middle_sort(t_list **pile_a, t_list **pile_b)
{
	int	size;
	int	n_of_pb;
	int	key_nbr;
	int	orig_key_nbr;

	size = ft_lstsize(*pile_a); //ex, size = 12
	orig_key_nbr = size / 4; //save the original key_nbr. ex, 12 / 4
	key_nbr = orig_key_nbr;
	n_of_pb = 0;
	while (size <= 100 && key_nbr < (4 * orig_key_nbr))
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
		key_nbr += orig_key_nbr; // 3 + 3 + 3, then while loop stops
	}
}
