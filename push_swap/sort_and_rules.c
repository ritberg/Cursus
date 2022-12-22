/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_and_rules.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:40:20 by mmakarov          #+#    #+#             */
/*   Updated: 2022/12/22 17:38:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	min_index(t_list *pile_a)
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
}

t_list	sort_and_rules(t_list *pile_a, t_list *pile_b)
{
	int	middle;
	int	index;
	int	size;

	size = ft_lstsize(pile_a);
	index = min_index(pile_a);
	if (size <= 10)
	{
		middle = size / 2;
		if (middle > index)
			ra(); // write functions rra, ra
		else
			rra();
	}
	if (size > 10 && size <= 100)
	{
	}
	if (size > 100 && size <= 500)

