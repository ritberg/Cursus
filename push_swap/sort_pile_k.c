/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pile_k.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:23:28 by mmakarov          #+#    #+#             */
/*   Updated: 2023/01/10 17:41:55 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *one, t_list *two)
{
	int	k;

	k = one->content;
	one->content = two->content;
	two->content = k;
}

void	get_index(t_list *pile_k, t_list *pile_a)
{
	int		ind;
	t_list	*start;

	start = pile_k;
	while (pile_a != NULL)
	{
		ind = 1;
		while (pile_a->content != pile_k->content)
		{
			pile_k = pile_k->next;
			ind++;
		}
		pile_a->content = ind;
		pile_a = pile_a->next;
		pile_k = start;
	}
}

void	sort_pile_k(t_list *pile_a, int argc, char **argv)
{
	t_list	*start;
	t_list	*pile_k;
	int		size;

	pile_k = create_pile(argc, argv); //create pile_k with new arc, argv
	size = ft_lstsize(pile_k);
	start = pile_k;
	while (size > 0)
	{
		while (pile_k->next != NULL)
		{
			if (pile_k->content > pile_k->next->content)
				swap(pile_k, pile_k->next);
			pile_k = pile_k->next;
		}
		pile_k = start;
		size--;
	}
	get_index(pile_k, pile_a); //replace numbers in pile_a with index
							   // from pile_k
}
//pas de return de pile dans sort_pile_k() ni index() car le pointer reste
//le meme, c'est le contenu qui change
