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

static int	min_index(t_list *pile_a)
{
	int	min;
	int	j;
	int	index;

	j = 1;
	min = 2147483647;
	while (pile_a != NULL)
	{
		if (pile_a->content < min) //if an elem of pile_a < min
		{
			min = pile_a->content; // it becomes min
			index = j;
		}
		pile_a = pile_a->next; //take next elem of pile_a
		j++;
	}
	return (index);
}

t_list	*small_sort(t_list *pile_a, t_list *pile_b)
{
	int	middle;
	int	index;
	int	size;
	char	c; // put char c somewhere to choose between pila a and pile b

	size = ft_lstsize(pile_a);
	index = min_index(pile_a);
	if (size <= 10)
	{
		middle = size / 2;
		if (middle > index)
			ra(); //while loop or function if I need commands several times
		else
			rra();
	}
	return (pile_a);
}

