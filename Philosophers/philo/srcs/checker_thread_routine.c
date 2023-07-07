/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_thread_routine.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:23:38 by mmakarov          #+#    #+#             */
/*   Updated: 2023/07/07 15:33:15 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incls/philo.h"

int	simulation_stops_def(t_data *data)
{
	int	stop;

	stop = 0;
	pthread_mutex_lock(&data->stop_lock);
	if (data->dead == 1)
		stop = 1;
	pthread_mutex_unlock(&data->stop_lock);
	return (stop);
}

void	simulation_stops(t_data *data, int i)
{
	pthread_mutex_lock(&data->stop_lock);
	data->dead = i;
	pthread_mutex_unlock(&data->stop_lock);
}

/*
	If current time - last_meal_time >= time_to_die, print a message "is dead",
	set the flag to 1 (philo, DIED, 1) and stop the simulation.
*/
int	is_dead(t_philo *philo)
{
	if ((get_current_time() - philo->last_meal_time) \
			>= philo->data->time_to_die)
	{
		simulation_stops(philo->data, 1);
		print(philo, DIED, 1);
		pthread_mutex_unlock(&philo->meal_lock);
		return (1);
	}
	return (0);
}

/*
	Here there are two things that will be checked:
	1. Is there the 5th arg? If yes, each philo should eat "times_must_eat" times
		(there is a flag all_ate that is initialized to 1. the simulation stops
		if it is set to 1. if not, we continue till the philos ate "times_must_eat")
	2. Did a philo die?
*/
int	end(t_data *data)
{
	int	i;
	int	all_ate;

	all_ate = 1;
	i = 0;
	while (i < data->n_philos)
	{
		pthread_mutex_lock(&data->philosophers[i].meal_lock);
		if (is_dead(&data->philosophers[i]))
			return (1);
		if (data->times_must_eat != NO_FIFTH_ARG)
			if (data->philosophers[i].times_ate < data->times_must_eat)
				all_ate = 0;
		pthread_mutex_unlock(&data->philosophers[i].meal_lock);
		i++;
	}
	if (data->times_must_eat != NO_FIFTH_ARG && all_ate == 1)
	{
		simulation_stops(data, 1);
		return (1);
	}
	return (0);
}

/*
	The checker thread controlls in an infinite while loop whether a philo died
	or not and whether the simulation should stop or not
	(initially simulation_stops(data, 0), but (data, 1) when it stops)
*/
void	*check_routine(void *ptr)
{
	t_data	*data;

	data = (t_data *)ptr;
	simulation_stops(data, 0);
	while (1)
	{
		if (end(data) == 1)
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
