/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:33:45 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/20 11:37:30 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_di(va_list args)
{
	int		i;
	int		len;
	char	*str;

	i = va_arg(args, int);
	ft_putnbr_fd(i, STDOUT_FILENO);
	str = ft_itoa(i);
	len = ft_strlen(str);
	free(str);
	return (len);
}
