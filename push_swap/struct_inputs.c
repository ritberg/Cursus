/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_inputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:21:54 by mmakarov          #+#    #+#             */
/*   Updated: 2022/12/22 14:25:33 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	struct_inputs(int argc, char **argv)
{
	int	j;
	long long	a;
	t_list	**str_inputs;
	t_list	*new;

	j = 1;
	while (j < argc)
	{
		a = ft_atoi(argv[j]);
		new = ft_lstnew(&a);
		ft_lstadd_back(str_inputs, new);
		j++;
	}
}
