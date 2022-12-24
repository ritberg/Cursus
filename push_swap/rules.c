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

static	void	write_rra_rrb(char c)
{
	if (c == 'a')
		write(1, "rra\n", 4);
	if (c == 'b')
		write(1, "rrb\n", 4);
}

t_list	*rra_rrb(t_list *pile, int size, char c)
{
	int	count;
	t_list	*current;
	t_list	*ind_node;

	if (size == 1) // if there is only 1 elem in pile_a
		return (pile);
	count = 1;
	ind_node = NULL;
	current = pile;
	while (count < size - 1) // go down, to the 2nd before null
	{
		current = current->next;
		count++;
	}
	ind_node = current; //save the 2nd before null
	current = current->next; //the last before null
	current->next = pile; //after current->next, pile_a starts
	pile = current;       //from the top
	ind_node->next = NULL;
	write_rra_rrb(c);
	return (pile);
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
