/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:32:55 by mmakarov          #+#    #+#             */
/*   Updated: 2023/07/07 17:48:32 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incls/philo.h"

/*
   Customized ft_usleep function.
   Standard usleep function sleeps longer than expected
   (than microseconds “usec” given in params).
   It leads to a philo death. That’s why we need a ft_usleep function
   that takes a param in milliseconds.
	1. Initialize start time of this function
	2. Initialize current time
	3. In a while loop, we imitate waiting for ms time.
	While current time - start time (both transformed in milliseconds)
	is bigger than given time ms → usleep(1).
*/
void	ft_usleep(t_data *data, int ms)
{
	struct timeval	start;
	struct timeval	now;

	gettimeofday(&start, 0);
	gettimeofday(&now, 0);
	while (((now.tv_sec - start.tv_sec) * \
				1000 + (now.tv_usec - start.tv_usec) / 1000) < ms)
	{
		if (simulation_stops_def(data) == 1)
			break ;
		usleep(1);
		gettimeofday(&now, 0);
	}
}

/*
void	ft_usleep(t_data *data, time_t sleep_time)
{
	time_t	wake_up;

	wake_up = get_current_time() + sleep_time;
	while (get_current_time() < wake_up)
	{
		if (simulation_stops_def(data) == 1)
			break ;
		usleep(100);
	}
}
*/
/*
	This function uses the gettimeofday() to get the current time
	in seconds and microseconds. It then converts the time to milliseconds
	and returns it as a time_t value.
	
	Second param of gettimeofday is a time zone, no need for the project;
	tv_sec - seconds since the Unix epoch (January 1, 1970);
	tv_usec - microseconds (1/1,000,000th of a second).
*/
time_t	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	ft_atoi(char *str)
{
	int						i;
	unsigned long long int	result;

	i = 0;
	result = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (result > INT_MAX)
		return (BIGGER_THAN_INTMAX);
	return ((int)result);
}

int	is_digit(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}
