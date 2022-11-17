/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:53:44 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/17 16:03:18 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_percent(const char *s, int ind, va_list args)
{
	int	count;

	count = 0;
	while (s[ind])
	{
		ft_putchar(s[ind]);
		ind++;
		count++;
	}
	return (count);
}
