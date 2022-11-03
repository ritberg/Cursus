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

int	ft_size(int n)
{
	int	size;  //len of the str (called result)

	if (n < 0)
	{
		n = (-1) * n;
		size = 1;
	}
	else
		size = 0;
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	
	return (size);
}
	
char	*ft_strcat(char *src, char *dst)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dst[j])
		j++;
	while (src[i])
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	return (dst);
}

void	ft_mod(int n, char *result)
{
	int	mod;
	int	i;

	if (n < 0)
	{
		i = 1;
		n = (-1) * n;
	}
	else
		i = 0;
	while (n > 0)
	{
		n = n / 10;
		mod = n % 10 + '0';
		result[i] = mod;
		i++;
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	int	size;

	if (n == 0)
		return ("0");
	else
	{
		size = ft_size(n);
		result = malloc(sizeof(char) * size);
		ft_mod(n, result);
	}
//	else if (n == -2147483648)
//		result = "-2147483648";
	if (n < 0)
	{
		n = n * (-1);
		result[0] = '-';
	}
	return (result);
}
