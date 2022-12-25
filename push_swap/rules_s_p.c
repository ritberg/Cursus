/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_s_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:57:38 by mmakarov          #+#    #+#             */
/*   Updated: 2022/12/23 17:52:27 by mmakarov         ###   ########.fr       */
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

t_list	*sa_sb(t_list *pile, char c)
{
	t_list	*first;
	t_list	*third;
	int	count;

	count = 1;
	if (size == 1) // if there is only 1 elem in pile
		return (pile);
	third = pile;
	while (count < 3)
	{
		third = third->next; //go to the third elem and save it
		count++;
	}	
	first = pile; //save the first elem
	pile = pile->next; //now pile starts from the 2nd elem
	pile->next = first; //put first after 2nd elem
	first->next = third; // put third elem after first
	write_sa_sb(c);
	return (pile);
}

static	void	write_pa_pb(char c)
{
	if (c == 'a')
		write(1, "pa\n", 3);
	if (c == 'b')
		write(1, "pb\n", 3);
}

t_list	*pa(t_list *pile_a, t_list *pile_b, char c)
{
	if (pile_b == NULL)
		return (NULL); //ne fait rien si pile_b est vide
	pile_a = pile_b;
	write_pa_pb(c);
	return (pile_a);
}

t_list	*pa(t_list *pile_a, t_list *pile_b, char c)
{
	if (pile_a == NULL)
		return (NULL); //ne fait rien si pile_b est vide
	pile_b = pile_a;
	write_pa_pb(c);
	return (pile_b);
}
