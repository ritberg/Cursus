/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   very_small_sort_r.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:40:20 by mmakarov          #+#    #+#             */
/*   Updated: 2023/01/11 18:38:14 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	t_list	*commands1(t_list *pile_b)
{
	t_list	*temp;

	temp = ra_rb(pile_b, 3, 'b');
	return (sa_sb(temp, 3, 'b'));
}

static	t_list	*commands2(t_list *pile_b)
{
	t_list	*temp;

	temp = rra_rrb(pile_b, 3, 'b');
	return (sa_sb(temp, 3, 'b'));
}

t_list	*very_small_sort_r(t_list *pile_b)
{
	t_list	*f;
	t_list	*s;
	t_list	*t;

	f = pile_b;
	s = pile_b->next;
	t = s->next;
	if (f->content > s->content && s->content < t->content \
			&& t->content > f->content)
		return (rra_rrb(pile_b, 3, 'b'));
	else if (f->content < s->content && s->content < t->content \
			&& f->content < t->content)
		return (commands1(pile_b));
	else if (f->content > s->content && s->content < t->content \
			&& f-> content > t->content)
		return (commands2(pile_b));
	else if (f->content < s->content && s->content > t->content \
			&& t->content > f->content)
		return (ra_rb(pile_b, 3, 'b'));
	else if (f->content < s->content && s->content > t->content \
			&& t->content < f->content)
		return (sa_sb(pile_b, 3, 'b'));
	else
		return (pile_b);
}
