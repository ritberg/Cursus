/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:57:38 by mmakarov          #+#    #+#             */
/*   Updated: 2023/01/10 17:41:32 by mmakarov         ###   ########.fr       */
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
	int		count;
	t_list	*current;
	t_list	*ind_node;

	if (size == 1) // if there is only 1 elem in pile
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
	current->next = pile; //after current->next, pile starts from the top
	pile = current;
	ind_node->next = NULL;
	write_rra_rrb(c);
	return (pile);
}

static	void	write_ra_rb(char c)
{
	if (c == 'a')
		write(1, "ra\n", 3);
	if (c == 'b')
		write(1, "rb\n", 3);
}

t_list	*ra_rb(t_list *pile, int size, char c)
{
	int		count;
	t_list	*last;
	t_list	*top;

	count = 1;
	last = pile;
	while (count < size)
	{
		last = last->next;
		count++;
	}
	top = pile;
	pile = pile->next;
	top->next = NULL;
	last->next = top;
	write_ra_rb(c);
	return (pile);
}
