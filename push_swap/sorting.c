/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:17:11 by mmakarov          #+#    #+#             */
/*   Updated: 2022/12/19 16:42:00 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

char	sorting(int *number, int total_num)
{
	int	smallest_int;
	int	longest_int;
	int	read_bytes;
	int	*temp;

	read_bytes = 1;
	temp = malloc(sizeof(int) * total_num);
	if (temp == NULL)
		return (NULL);
	while (read_bytes != 0)
	{
		read_bytes = read(STDIN_FILENO, number, total_num);
		if (read_bytes == -1) // -1 is retured if there is an error
			return ("Error");
	}
