/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:40:46 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/17 16:22:18 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_n(const char *s, int ind, va_list args)
{
	int		i;
	int		len;
	char	*str;

	i = va_arg(args, int);
	//ft_putnbr(i);
	str = ft_itoa(i);
	len = ft_strlen(str);
	return (len);
}
