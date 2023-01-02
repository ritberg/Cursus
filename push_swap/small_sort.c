/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:40:20 by mmakarov          #+#    #+#             */
/*   Updated: 2023/01/02 18:09:37 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min_index(t_list *pile) //find min and give an index to it (from 1)
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

static int	max_index(t_list *pile) //find min and give an index to it (from 1)
{
	int	max;
	int	j;
	int	index;

	j = 1;
	max = -2147483648;
	while (pile != NULL)
	{
		if (pile->content > max) //if an elem of pile_a > max
		{
			max = pile->content; // it becomes max
			index = j;
		}
		pile = pile->next; //take next elem of pile_a
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
			**pile_a = ra_rb(**pile_a, size, 'a'); //all commands several times
			count++;               //pile_a = .. - save modified param pile_a
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

void	small_sort(t_list **pile_a, t_list **pile_b, int direction) //modify addresses? 
{
	int	middle;
	int	index;
	int	size;
	int	count;

	size = ft_lstsize(*pile_a);
	while (size > 3)
	{
		count = 1;
		if (direction == MIN_TO_MAX) // if size <= 10
			index = min_index(*pile_a);
		middle = size / 2;
		/*
		if (middle > index)
		{
			while (count < index)
			{
				*pile_a = ra_rb(*pile_a, size, 'a'); //all commands several times
				count++;               //pile_a = .. - save modified param pile_a
			}
		}
		else
		{
			while (count <= size - index + 1)
			{
				*pile_a = rra_rrb(*pile_a, size, 'a');
				count++;
			}
		}
		*/
		commands(&pile_a, middle, index, size);
		pb(pile_a, pile_b);
		size--; //size decreases -1 after each while loop
	}	
	*pile_a = very_small_sort(*pile_a);
//	while (*pile_b != NULL)
//		pa(pile_a, pile_b);
}
