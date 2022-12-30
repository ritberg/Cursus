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
	int	dist_head;

	size = ft_lstsize(*pile_a);
	key_nbr = size / 4;
	while (size <= 100 && key_nbr <= size / 4)
	{
		while (pile_a != NULL)
		{
			if ((*pile_a)->content <= key_nbr)
			{
				count = 1;
				middle = size / 2;
				if (middle > dist_head)
				{
					while (count < dist_head)
					{
						*pile_a = ra_rb(*pile_a, size, 'a');
						count++;
					}
				}
				else
				{
					while (count <= size - dist_head + 1)
					{
						*pile_a = rra_rrb(*pile_a, size, 'a');
						count++;
					}
				}
				pb(pile_a, pile_b);
				dist_head = 1;
				size--;
			}
			else
			{
				*pile_a = (*pile_a)->next;
				dist_head++;
			}
		}
		key_nbr += (size / 4);
	}
}
