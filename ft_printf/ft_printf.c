/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:50:09 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/13 12:06:46 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *, ...)
{
	const char	*s;
	va_list	args;
	int	i;

	va_start(args, s);

	while (*s)
	{
		if (*s == 'd')
		{
			i = va_arg(args, int);
			ft_itoa(i);
		}
		s++;
	}
	va_end(args);
}
