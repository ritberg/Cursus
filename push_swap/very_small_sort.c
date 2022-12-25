/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   very_small_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:40:20 by mmakarov          #+#    #+#             */
/*   Updated: 2022/12/23 18:03:20 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	commands1(t_list *pile_a)
{
	sa_sb(pile_a, 3, 'a');
	rra_rrb(pile_a, 3, 'a');
}

static	void	commands2(t_list *pile_a)
{
	sa_sb(pile_a, 3, 'a');
	ra_rb(pile_a, 3, 'a');
}

t_list	*very_small_sort(t_list *pile_a)
{
	t_list	*f;//first n
	t_list	*s;//second n
	t_list	*t;//third n

	f = pile_a;
	s = pile_a->next;
	t = s->next;
	if (f->content > s->content && s->content < t->content\
			&& t->content > f->content)
		sa_sb(pile_a, 3, 'a');
	else if (f->content > s->content && s->content > t->content\
			&& f->content > t->content)
		commands1(pile_a);
	else if (f->content > s->content && s->content < t->content\
			&& f-> content > t->content)
		ra_rb(pile_a, 3, 'a');
	else if (f->content < s->content && s->content > t->content\
			&& t->content > f->content)
		commands2(pile_a);
	else
		rra_rrb(pile_a, 3, 'a');
	return (pile_a);
}

