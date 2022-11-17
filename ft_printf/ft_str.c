/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:41:10 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/17 13:37:50 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_str(const char *s, int ind, va_list args)
{
	char	*str;
	int	len;

	str = va_arg(args, char *);
	ft_putstr(str);
	len = ft_strlen(str);
	return (len);
}
