/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:30:51 by mmakarov          #+#    #+#             */
/*   Updated: 2022/10/27 12:47:48 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char ch;
	char	*sb;
	int	i;

	ch = (unsigned char)c;
	sb = b;
	i = 0;
	while (sb[i])
	{
		if (i == len)
			b[i] = sb[i];
		i++;
	}
}
