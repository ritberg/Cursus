/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:14:14 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/20 17:23:02 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(va_list args)
{
	void	*p;
	unsigned int	u;

	p = va_arg(args, void *);
	u = (unsigned int)p; //long int?
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	return (ft_dec_to_hexadec_p(u));
}
