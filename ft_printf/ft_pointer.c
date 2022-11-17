/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:14:14 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/17 15:43:37 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(const char *s, int ind, va_list args)
{
	void	*p;
	long int	l;

	p = va_arg(args, void *);
	l = (long int)p; //long int or not?
	ft_putchar('0');
	ft_putchar('x');
	return (ft_dec_to_hexadec_p(l));
}
