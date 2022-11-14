/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:48:02 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/14 14:53:53 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_mod(int nb)
{
	int	mod;

	if (nb != 0)
	{
		ft_mod(nb / 10);
		mod = nb % 10 + '0';
		write(1, &mod, 1);
	}
}

void	ft_putnbr(int nb)
{
	if (nb > 0)
		ft_mod(nb);
	else if (nb == 0)
		write(1, "0", 1);
	else if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		nb = nb * (-1);
		write(1, "-", 1);
		ft_mod(nb);
	}
}
