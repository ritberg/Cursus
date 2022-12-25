/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:40:20 by mmakarov          #+#    #+#             */
/*   Updated: 2022/12/23 18:03:20 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min_index(t_list *pile)
{
	int	min;
	int	j;
	int	index;

	j = 1;
	min = 2147483647;
	while (pile != NULL)
	{
		if (pile->content < min) //if an elem of pile_a < min
		{
			min = pile->content; // it becomes min
			index = j;
		}
		pile = pile->next; //take next elem of pile_a
		j++;
	}
	return (index);
}

t_list	*small_sort(t_list *pile_a, t_list *pile_b)
{
	int	middle;
	int	index;
	int	size;
	int	count;

	while (size > 3 && size <= 10)
	{
		count = 1;
		size = ft_lstsize(pile_a);
		index = min_index(pile_a);
		middle = size / 2;
		if (middle > index)
		{
			while (count < index)
			{
				ra_rb(pile_a, size, 'a'); //while loop, because I need commands several times
				count++;
			}
		}
		else
			while (count <= size - index + 1)
			{
				rra_rrb(pile_a, size, 'a');
				count++;
			}
		pb(pile_a, pile_b);
	}
	very_small_sort(pile_a);
	while (pile_b != NULL)
		pa(pile_a, pile_b);
	return (pile_a);
}

