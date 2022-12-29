/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:34:18 by mmakarov          #+#    #+#             */
/*   Updated: 2022/12/29 18:10:05 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	middle_sort(t_list **pile_a, t_list **pile_b)
{
	int	size;
	int	key_nbr;
	int	count;
	int	middle;

	size = ft_lstsize(*pile_a);
	key_nbr = 25;
	while (size > 10 && size <= 100)
	{
		while ((*pile_a)->content <= key_nbr && key_nbr <= 75)
		{
			count = 1;
			middle = key_nbr / 2; // 25/2 or 100/2?
			if (middle > key_nbr)
			{
				while (count < key_nbr)
				{
					*pile_a = ra_rb(*pile_a, size, 'a');
					count++;
				}
			}
			else
			{
				while (count <= size - key_nbr + 1) //without +1 ?
				{
					*pile_a = rra_rrb(*pile_a, size, 'a');
					count++;
				}
			}
			pb(pile_a, pile_b);
			size--;
			*pile_a = (*pile_a)->next;
			key_nbr += 25;
		}
	}
}
