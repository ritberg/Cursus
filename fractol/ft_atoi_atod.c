/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_atod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:30:14 by mmakarov          #+#    #+#             */
/*   Updated: 2023/03/23 14:51:30 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'\
			|| c == '\v' || c == '\f' || c == '\r');
}

double	ft_atod(const char *str)
{
	int	i;
	int	sign;
	double	d;
	double	result;

	i = 0;
	sign = 1;
	d = 10.0;
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
	if (!str[i]) // s'il y a pas de point
		return (result * sign);
	i++; // pour le point
	while (str[i])
	{
		result += (double)(str[i] - '0') / d;
		d *= 10.0;
		i++;
	}
	return (result * sign);
}

long long int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long long int	result;

	i = 0;
	sign = 1;
	result = 0;
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
	return (result * sign);
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
