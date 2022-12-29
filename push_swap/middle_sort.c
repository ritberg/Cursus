/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:34:18 by mmakarov          #+#    #+#             */
/*   Updated: 2022/12/29 14:24:47 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*sa_without_write(t_list *pile, int size)
{
	t_list	*first;
	t_list	*third;
	int		count;

	count = 1;
	if (size == 1)
		return (pile);
	third = pile;
	while (count < 3)
	{
		third = third->next;
		count++;
	}
	first = pile;
	pile = pile->next;
	pile->next = first;
	first->next = third;
	return (pile);
}

static	t_list	*sort_pile_k(**pile_a, int size)
{
	t_list	*start;

	start = *pile_a;
	while (size > 0)
	{
		while (*pile_a != NULL)
		{
			if ((*pile_a)->content > (*pile_a)->next)
				*pile_a = sa_without_write(*pile_a, size);
			*pile_a = (*pile_a)->next;
		}
		*pile_a = start;
		size--;
	}
	return (pile_a);
}

void	middle_sort(t_list **pile_a, t_list **pile_b)
{
	t_list	*pile_k;
	int	size;
	int	key_nbr;
	int	count;
	int	middle;
	int	index;

	/*
	 find the number with index 25 in pile_k (it is key_nbr)
	 if number of pile_a <= key_nbr, put it on top and pb
	 (without sorting)
	*/

	size = ft_lstsize(*pile_a);
	pile_k = sort_pile_k(*pile_a, size);
	index = 25;
	while (size > 10 && size <= 100 && index <= 75)
	{
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
