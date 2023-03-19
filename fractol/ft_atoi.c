/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:30:14 by mmakarov          #+#    #+#             */
/*   Updated: 2023/03/19 19:39:19 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'\
			|| c == '\v' || c == '\f' || c == '\r');
}

double	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	double	result;

	i = 0;
	sign = 1;
	result = 0.0;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '0' && str[i + 1] == '.')
	{
		result = 0.0;
		i++;
	}
	if (str[i] == '1' && str[i + 1] == '.')
	{
		result = 1.0;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
