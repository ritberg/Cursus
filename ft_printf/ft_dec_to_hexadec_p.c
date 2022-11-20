/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hexadec_p.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:46:19 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/20 19:17:50 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dec_to_hexadec_p(unsigned long i) //uintptr_t?
{
	unsigned long	n;
	char		hexadec[1000];
	int		j;
	int		k;

	j = 0;
	while (i != 0)
	{
		n = i % 16;
		if (n < 10)
			hexadec[j++] = n + 48;
		else
			hexadec[j++] = n + 87; //minuscule 97 - 10 in ascci
		i = i / 16;
	}
	k = j - 1;
	while (k >= 0)
	{
		ft_putchar_fd(hexadec[k], STDOUT_FILENO);
		k--;
	}
	return (j);
}
