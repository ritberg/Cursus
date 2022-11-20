/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:46:04 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/20 18:01:46 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_min(va_list args)
{
	unsigned int	i;

	i = va_arg(args, unsigned int);
	if (i == 0)
	{
		ft_putchar_fd('0', STDOUT_FILENO);
		return (1);
	}
	return (ft_dec_to_hexadec_min(i));
}
