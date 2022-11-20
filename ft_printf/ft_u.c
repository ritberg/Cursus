/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:35:18 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/20 11:37:11 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_u(va_list args)
{
	unsigned int	u;
	int				len;
	char			*str;

	u = va_arg(args, unsigned int);
	ft_putnbr_fd(u, STDOUT_FILENO);
	str = ft_itoa_unsigned(u);
	len = ft_strlen(str);
	free(str);
	return (len);
}
