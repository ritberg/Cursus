/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:34:18 by mmakarov          #+#    #+#             */
/*   Updated: 2022/12/28 16:20:38 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	t_list	sort_pile_k(***pile_a, int size)
{
	while (size > 0)
	{
		if ((**pile_a)->content > (**pile_a)->next)
			**pile_a = sa_sb(**pile_a, size, 'a');
		**pile_a = (**pile_a)->next;
		size--;
	}
	return (pile_a); //does this consider the top and the last elems?
}

void	middle_sort(**pile_a)
{
	t_list	*pile_k;
	int	size;
	int	key_nbr;
	int	count;
	int	middle;

	size = ft_lstsize(*pile_a);
	pile_k = sort_pile_k(*pile_a, size);
	key_nbr = ft_lstsize(pile_k) / 4;
	while (size > 10 && size <= 100)
	{
		count = 1;
		middle = key_nbr / 2;
		if (middle > key_nbr)
		{
			while (count <= key_nbr)
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
	}
	*pile_a = very_small_sort(*pile_a);
	while (*pile_b != NULL)
		pa(pile_a, pile_b);
}
