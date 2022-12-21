/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:13:53 by mmakarov          #+#    #+#             */
/*   Updated: 2022/12/21 16:14:44 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// replace numbers like -20 87 3 by new index 0 2 1

int	new_index(int argc, int &read_input[])
{
	int	smallest_int;
	int	**new_ind_tab;

	new_ind_tab = malloc(sizeof(**int) * argc - 1);
	if (new_ind_tab == 0)
		return (0);
	smallest_int = malloc(sizeof(int) * 1);
	if (smallest_int == 0)
		return (0);
	smallest_int = read_input[0];
	while (ft_lstnew(read_input[]))
	{
		if (smallest_int > read_input.next) //?
			smallest_int = read_input.next;
		new_ind_tab = smallest_int;
	}
}
