/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   very_small_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:40:20 by mmakarov          #+#    #+#             */
/*   Updated: 2022/12/28 13:38:23 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* before I called functions-commands sa_sb, rra_rrb etc.
   now I have returns of these functions-commands 
   otherwise I loose the modified param pile_a
*/
static	t_list	*commands1(t_list *pile_a)
{
	t_list	*temp;

	temp = sa_sb(pile_a, 3, 'a');
	return (rra_rrb(temp, 3, 'a'));
}

static	t_list	*commands2(t_list *pile_a)
{
	t_list	*temp;

	temp = sa_sb(pile_a, 3, 'a');
	return (ra_rb(temp, 3, 'a'));
}

t_list	*very_small_sort(t_list *pile_a)
{
	t_list	*f;//first n
	t_list	*s;//second n
	t_list	*t;//third n

	f = pile_a;
	s = pile_a->next;
	t = s->next;
	if (f->content > s->content && s->content < t->content \
			&& t->content > f->content)
		return (sa_sb(pile_a, 3, 'a'));
	else if (f->content > s->content && s->content > t->content \
			&& f->content > t->content)
		return (commands1(pile_a));
	else if (f->content > s->content && s->content < t->content \
			&& f-> content > t->content)
		return (ra_rb(pile_a, 3, 'a'));
	else if (f->content < s->content && s->content > t->content \
			&& t->content > f->content)
		return (commands2(pile_a));
	else if (f->content < s->content && s->content > t->content \
			&& t->content < f->content)
		return (rra_rrb(pile_a, 3, 'a'));
	else
		return (pile_a);
}

