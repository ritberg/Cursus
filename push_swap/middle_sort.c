/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:34:18 by mmakarov          #+#    #+#             */
/*   Updated: 2022/12/29 17:05:34 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	middle_sort(t_list **pile_k, t_list **pile_a, t_list **pile_b)
{
	int	size;
	int	key_nbr;
	int	count;
	int	middle;
	int	index;

	/*
	 find the number with index 25 in pile_k (it is key_nbr)
	 if number of pile_a <= key_nbr, put it on top and pb
	 (without sorting - ???)
	*/

	size = ft_lstsize(*pile_k);
	while (size > 10 && size <= 100 && index <= 75)
	{
		index = 25;
		count = 1;
		while (count <= index)
		{
			pile_k = pile_k->next;
			count++;
		}
		key_nbr = pile_k->content;
		while ((*pile_a)->content <= key_nbr)
		{
			count = 1;
			middle = size / 2;
			if (middle > index)
			{
				while (count < index)
				{
					*pile_a = ra_rb(*pile_a, size, 'a');
					count++;
				}
			}
			else
			{
				while (count <= size - index + 1) //without +1 ?
				{
					*pile_a = rra_rrb(*pile_a, size, 'a');
					count++;
				}
			}
			pb(pile_a, pile_b);
			size--;
			index += 25;
		}
	}
}
