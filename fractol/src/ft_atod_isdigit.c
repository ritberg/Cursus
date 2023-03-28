/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:30:14 by mmakarov          #+#    #+#             */
/*   Updated: 2023/03/28 10:37:46 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'\
			|| c == '\v' || c == '\f' || c == '\r');
}

static double	ft_atod_return(int i, const char *str, double res, double sign)
{
	double	d;

	d = 10.0;
	if (!str[i]) // s'il y a pas de point
		return (res * sign);
	i++; // pour le point
	while (str[i])
	{
		res += (double)(str[i] - '0') / d;
		d *= 10.0;
		i++;
	}
	return (res * sign);
}

double	ft_atod(const char *str)
{
	int		i;
	double	sign;
	double	result;

	i = 0;
	sign = 1.0;
	result = 0.0;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (ft_atod_return(i, str, result, sign));
}

int	ft_isdigit(char *str)
{
	int	i;
	int	count;

	if (!((str[0] >= '0' && str[0] <= '9') || str[0] == '-'))
		return (0);
	i = 1;
	count = 0;
	while (str[i])
	{
		if (str[i] == '.')
			count++;
		i++;
	}
	i = 1;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '.') && count != 1)
			return (0);
		i++;
	}
	return (1);
}
