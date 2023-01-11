/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:40:20 by mmakarov          #+#    #+#             */
/*   Updated: 2023/01/11 18:35:30 by mmakarov         ###   ########.fr       */
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
		if (pile->content < min)
		{
			min = pile->content;
			index = j;
		}
		pile = pile->next;
		j++;
	}
	return (index);
}

static	void	commands(t_list ***pile_a, int middle, int index, int size)
{
	int	count;

	count = 1;
	if (middle > index)
	{
		while (count < index)
		{
			**pile_a = ra_rb(**pile_a, size, 'a');
			count++;
		}
	}
	else
	{
		while (count <= size - index + 1)
		{
			**pile_a = rra_rrb(**pile_a, size, 'a');
			count++;
		}
	}
}

void	small_sort(t_list **pile_a, t_list **pile_b, int direction)
{
	int	middle;
	int	index;
	int	size;

	size = ft_lstsize(*pile_a);
	while (size > 3)
	{
		if (direction == MIN_TO_MAX)
			index = min_index(*pile_a);
		middle = size / 2;
		commands(&pile_a, middle, index, size);
		pb(pile_a, pile_b);
		size--;
	}	
	*pile_a = very_small_sort(*pile_a);
}
