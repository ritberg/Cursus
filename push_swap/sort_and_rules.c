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
/* rappel
static void	swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}
*/

static void	min_index(t_list **pile_a)
{
	t_list	min;

	min = pile_a->content; // the first elem of pile_a becomes min
	if (pile_a->next < min) //if next < min, it becomes min
		min = pile_a->next;
}

t_list	sort_and_rules(t_list **pile_a, t_list **pile_b)
{
	int	middle;
	int	index;

	index = min_index(pile_a);
	if (ft_lstsize(pile_a) <= 10)
	{
		middle = ft_lstsize(pile_a) / 2;
		if (middle > index)
			ra(); // write functions rra, ra
		else
			rra();
	}
	if (ft_lstsize(pile_a) > 10 && ft_lstsize(pile_a) <= 100)
	{
	}
	if (ft_lstsize(pile_a) > 100 && ft_lstsize(pile_a) <= 500)

