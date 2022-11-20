/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_maj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:42:52 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/20 18:02:02 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_maj(va_list args)
{
	unsigned int	i;

	i = va_arg(args, unsigned int);
	if (i == 0)
	{
		ft_putchar_fd('0', STDOUT_FILENO);
		return (1);
	}
	return (ft_dec_to_hexadec_maj(i));
}
