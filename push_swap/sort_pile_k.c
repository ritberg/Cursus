/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pile_k.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:23:28 by mmakarov          #+#    #+#             */
/*   Updated: 2022/12/29 17:28:21 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*sa_without_write(t_list *pile_k, int size)
{
	t_list	*first;
	t_list	*third;
	int		count;

	count = 1;
	if (size == 1)
		return (pile_k);
	third = pile_k;
	while (count < 3)
	{
		third = third->next;
		count++;
	}
	first = pile_k;
	pile_k = pile_k->next;
	pile_k->next = first;
	first->next = third;
	return (pile_k);
}

void	index(t_list *pile_k, t_list *pile_a)
{
	int	ind;
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
		pile_a->content = ind + 1;
		pile_a = pile_a->next;
		pile_k = start;
	}
}

void	sort_pile_k(t_list *pile_a)
{
	t_list	*start;
	t_list	*pile_k;
	int	size;

	pile_k = create_pile(argc, argv); //create pile_k with arc, argv
	size = ft_lstsize(pile_k);
	start = pile_k;
	while (size > 0)
	{
		while (*pile_k != NULL)
		{
			if (pile_k->content > pile_k->next)
				pile_k = sa_without_write(pile_k, size); //sort with sa
			pile_k = pile_k->next;
		}
		pile_k = start;
		size--;
	}
	index(pile_k, pile_a); //replace numbers in pile a with index
	                      // from pile_k
}

//pas de return de pile dans sort_pile_k() ni index() car le pointer reste
//le meme, c'est le contenu qui change
