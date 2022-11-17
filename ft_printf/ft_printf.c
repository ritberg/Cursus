/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:50:09 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/17 17:25:52 by mmakarov         ###   ########.fr       */
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

static int	ft_output_type(const char *s, int ind, va_list args)
{
	if (ft_check(s[ind + 1], "diu")) //putnbr works for d i u?
		ft_n(args); // to check. itoa instead of putnbr
	else if (s[ind + 1] == 'c')
		return (ft_c(args));
	else if (s[ind + 1] == 's')
		return (ft_str(args)); // +
	else if (s[ind + 1] == 'x')
		return (ft_hex_min(args)); //to check
	else if (s[ind + 1] == 'X')
		return (ft_hex_maj(args)); //to check
	else if (s[ind + 1] == 'p')
		return (ft_pointer(args)); //to check
	else if (s[ind + 1] == '%') //to check
	{
		ft_putchar_fd(s[ind], 1); //return un char apres l'autre
		return (1);
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int	ind;
	int	result;
	
	va_start(args, s);
	ind = 0;
	result = 0;
	while (s[ind])
	{
		if (s[ind] == '%')
		{
			result += ft_output_type(s, ind, args);
			ind += 2;
		}
		else
		{
			ft_putchar_fd(s[ind], 1);
			result++;
			ind++;
		}
	}
	va_end(args);
	return (result); //return is len of output
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
