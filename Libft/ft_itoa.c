/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:24:42 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/02 19:39:43 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mod(int n)
{
	int	mod;

	if (n != 0)
	{
		ft_mod(n / 10);
		mod = n % 10 + '0';
	}
}

char	*ft_itoa(int n)
{
	if (n > 0)
		ft_mod(n);
	else if (n == 0)
		return ("0");
	else if (n == -2147483648)
		return ("-2147483648");
	else if (n < 0)
	{
		n = n * (-1);
		return ("-");
		ft_mod(n);
	}
}
