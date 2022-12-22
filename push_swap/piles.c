/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:21:54 by mmakarov          #+#    #+#             */
/*   Updated: 2022/12/22 15:25:18 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	piles(int argc, char **argv)
{
	int	j;
	long long	a;
	t_list	**pile_a;
	t_list	**pile_b; //to do
	t_list	*new;

	j = 1;
	while (j < argc)
	{
		a = ft_atoi(argv[j]);
		new = ft_lstnew(&a);
		ft_lstadd_back(pile_a, new);
		j++;
	}
}
