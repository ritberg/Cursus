/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:50:09 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/16 17:23:54 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 if we have a even (pair) n of %, we can print. what to do if 5 %, for ex?? error!
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

static	void	ft_dec_to_hexadec_X(int i)
{
	int	n;
	char	hexadec[100];
	int	j;
	int	k;

	j = 0;
	while (i != 0)
	{
		n = i % 16;
		if (n < 10)
			hexadec[j++] = n + 48;
		else
			hexadec[j++] = n + 55; //for maj 55 (65 - 10  in ascii)
		i = i / 16;
	}
	k = j - 1;
	while (k >= 0)
	{
		ft_putchar(hexadec[k]);
		k--;
	}
}

static	void	ft_dec_to_hexadec_x(int i)
{
	int	n;
	char	hexadec[100];
	int	j;
	int	k;

	j = 0;
	while (i != 0)
	{
		n = i % 16;
		if (n < 10)
			hexadec[j++] = n + 48;
		else
			hexadec[j++] = n + 87; //97 - 10 in ascci
		i = i / 16;
	}
	k = j - 1;
	while (k >= 0)
	{
		ft_putchar(hexadec[k]);
		k--;
	}
}

static	void	ft_dec_to_hexadec_p(long int i)
{
	int	n;
	char	hexadec[100];
	int	j;
	int	k;

	j = 0;
	while (i != 0)
	{
		n = i % 16;
		if (n < 10)
			hexadec[j++] = n + 48;
		else
			hexadec[j++] = n + 87; //97 - 10 in ascci
		i = i / 16;
	}
	k = j - 1;
	while (k >= 0)
	{
		ft_putchar(hexadec[k]);
		k--;
	}
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int	ind;
	int	i;
	char	c;
	char	*str;
	void	*p;
	long int	l;
	
	va_start(args, s);

	ind = 0;
	while (s[ind])
	{
		if (s[ind] == '%' && ft_check(s[ind + 1], "diu")) // d, i and u are ok with ft_putnbr?
		{
			i = va_arg(args, int);
			ft_putnbr(i);
			ind += 2;
		}
		else if (s[ind] == '%' && s[ind + 1] == 'c')
		{
			c = va_arg(args, int);
			ft_putchar(c);
			ind += 2;
		}
		else if (s[ind] == '%' && s[ind + 1] == 's')
		{
			str = va_arg(args, char *);
			ft_putstr(str);
			ind += 2;
		}
		else if (s[ind] == '%' && s[ind + 1] == 'x')
		{
			i = va_arg(args, unsigned int);
			ft_dec_to_hexadec_x(i);
			ind += 2;
		}
		else if (s[ind] == '%' && s[ind + 1] == 'X')
		{
			i = va_arg(args, unsigned int);
			ft_dec_to_hexadec_X(i);
			ind += 2;
		}
		else if (s[ind] == '%' && s[ind + 1] == 'p')
		{
			p = va_arg(args, void *);
			l = (long int)p; //long int or not?
			ft_putchar('0');
			ft_putchar('x');
			ft_dec_to_hexadec_p(l);
			ind += 2;
		}
		else if (s[ind] == '%' && s[ind + 1] == '%')
		{
			ft_putchar(s[ind]);
			ind += 2;
		}
		else
			ind++;
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
