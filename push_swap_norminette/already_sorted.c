/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   already_sorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:21:39 by mmakarov          #+#    #+#             */
/*   Updated: 2023/01/10 18:32:32 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	already_sorted(t_list *pile_a)
{
	int	count;
	int	size;

	count = 1;
	size = ft_lstsize(pile_a);
	while (pile_a->next != NULL)
	{
		if (pile_a->content < pile_a->next->content)
			count++;
		pile_a = pile_a->next;
	}
	if (size == count)
		return (0);
	return (1);
}
