/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:50:09 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/14 19:29:00 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int	i;
	char	c;
	char	*str;
	void	*p;

	va_start(args, s);

	while (*s)
	{
		if (*s == 'd')
		{
			i = va_arg(args, int);
			//ft_putnbr(i);
		}
		else if (*s == 'c')
		{
			c = va_arg(args, int);
			//ft_putchar(c);
		}
		else if (*s == 's')
		{
			str = va_arg(args, char *);
			//ft_putstr(str);
		}
		else if (*s == 'p')
		{
			p = va_arg(args, void *);
			ft_putstr(p);
		}
		s++;
	}
	va_end(args);
	return (0); //or return (i) or return (c) ??
}
