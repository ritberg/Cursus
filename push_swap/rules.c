/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:57:38 by mmakarov          #+#    #+#             */
/*   Updated: 2022/12/23 17:52:27 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*rra(t_list *pile_a, int size)
{
	int	count;
	t_list	*current;
	t_list	*ind_node;

	if (size == 1) // if there is only 1 elem in pile_a
		return (pile_a);
	count = 1;
	ind_node = NULL;
	current = pile_a;
	while (count < size - 1) // go down, to the 2nd before null
	{
		current = current->next;
		count++;
	}
	ind_node = current; //save the 2nd before null
	current = current->next; //the last before null
	current->next = pile_a; //after current->next, pile_a starts
	pile_a = current;       //from the top
	ind_node->next = NULL;
	write(1, "rra\n", 4);
	return (pile_a);
}

t_list	*ra(t_list *pile_a, int index)
{
	int	count;
	t_list	*current;
	t_list	*ind_node;

	count = 1;
	ind_node = NULL;

	return (pile_a);
}

t_list	*pb(t_list *pile_a, t_list_pile_b)
t_list	*pa(t_list *pile_a, t_list_pile_b)
