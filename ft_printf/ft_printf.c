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

/*
 if we have a even (pair) n of %, we can print. what to do if 5 %, for ex??
*/

static int	ft_check(char c, const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int	index;
	int	n;
	int	i;
	char	c;
	char	*str;
	void	*p;
	
	va_start(args, s);

	index = 0;
	while (s[index])
	{
		if (s[index] == '%' && ft_check(s[index + 1], "diu")) // d, i and u are ok with ft_putnbr?
		{
			i = va_arg(args, int);
		//	ft_putnbr(i);
			index += 2;
		}
		else if (s[index] == '%' && s[index + 1] == 'c')
		{
			c = va_arg(args, int);
			//ft_putchar(c);
			index += 2;
		}
		else if (s[index] == '%' && s[index + 1] == 's')
		{
			str = va_arg(args, char *);
		//	ft_putstr(str);
			index += 2;
		}
		else if (s[index] == '%' && s[index + 1] == 'p')
		{
			p = va_arg(args, void *);
			ft_putstr(p);
			index += 2;
		}
		else
		{
		//	ft_putchar(s[index]);
			index += 1;
		}
	}
	va_end(args);
	return (0); //or return (i) or return (c) ??
}



/*
        n = 0;
        while (*s)
        {
                if (s[index] == '%') //if there is a %
                {
                        if (ft_check(s[index + 1], "cspdiuxX%")) //if the second is c or s or p etc.
                        {
                                index += 2; //skip the character right after % and go the the next one
                                n++; //count n of arguments to print like %d or %c
                        }
                }
                else
                        index += 1;
        }
*/
