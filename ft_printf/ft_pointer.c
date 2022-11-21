/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:14:14 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/21 07:27:23 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(va_list args)
{
	void	*p;
	unsigned long	l;

	p = va_arg(args, void *);
	if (p == NULL)
	{
		ft_putstr_fd("0x0", 1);
		return (3);
	}
	l = (unsigned long)p; //long int?
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	return (2 + ft_dec_to_hexadec_p(l));
}
