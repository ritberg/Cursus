/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:46:04 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/17 15:41:30 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_min(va_list args)
{
	int	i;

	i = va_arg(args, unsigned int);
	return (ft_dec_to_hexadec_min(i));
}
