/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_s_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:57:38 by mmakarov          #+#    #+#             */
/*   Updated: 2023/01/11 18:31:31 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	write_sa_sb(char c)
{
	if (c == 'a')
		write(1, "sa\n", 3);
	if (c == 'b')
		write(1, "sb\n", 3);
}

t_list	*sa_sb(t_list *pile, int size, char c)
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
	write_sa_sb(c);
	return (pile);
}

int	pa(t_list **pile_a, t_list **pile_b)
{
	t_list	*top;

	if (*pile_b == NULL)
		return (0);
	top = *pile_b;
	*pile_b = (*pile_b)->next;
	top->next = *pile_a;
	*pile_a = top;
	write(1, "pa\n", 3);
	return (1);
}

int	pb(t_list **pile_a, t_list **pile_b)
{
	t_list	*top;

	if (*pile_a == NULL)
		return (0);
	top = *pile_a;
	*pile_a = (*pile_a)->next;
	top->next = *pile_b;
	*pile_b = top;
	write(1, "pb\n", 3);
	return (1);
}
