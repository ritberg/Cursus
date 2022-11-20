/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:35:18 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/20 16:46:26 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_u(va_list args)
{
	unsigned int	u;
	int		len;
	char		*str;

	u = va_arg(args, unsigned int);
	str = ft_itoa_unsigned(u);
	ft_putstr_fd(str, STDOUT_FILENO); // easier to putstr than putnbr
	len = ft_strlen(str);           // because putnbr is for signed int
	free(str);
	return (len);
}
