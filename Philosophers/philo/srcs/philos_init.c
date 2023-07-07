/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <mmakarov@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:13:42 by mmakarov          #+#    #+#             */
/*   Updated: 2023/07/07 18:19:24 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incls/philo.h"

/*
	A function that prints messages "is eating, sleeping..."
	It stops printing if the simulation stops because a philo died
	(it is a permanent check when checker thread is activated)
*/
void	print(t_philo *philo, char *str, int stop)
{
	time_t	time;

	pthread_mutex_lock(&philo->data->print_lock);
	if (simulation_stops_def(philo->data) == 1 && stop == 0)
	{
		pthread_mutex_unlock(&philo->data->print_lock);
		return ;
	}
	time = get_current_time() - philo->data->start_time;
	printf("%ld %d %s", time, philo->p_id + 1, str);
	pthread_mutex_unlock(&philo->data->print_lock);
}

/*
	A special case for 1 philo.
	The checker doesn't check this case, so simulation_stops_def() = 0.
	That's why it dsn't matter print(philo, DIED, 1) or print(philo, DIED, 0).
*/
static void	*one_p_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print(philo, FORKS, 0);
	ft_usleep(philo->data, philo->data->time_to_die);
	print(philo, DIED, 1);
	pthread_mutex_unlock(philo->r_fork);
	return (NULL);
}

/*
	The function that is applied to each philosopher thread.
	! last_meal_time = start_time (got in p_threads initialization below)
	! in checker thread, current time - last_meal_time should be >= time_to_die
	! otherwise, a philo died
 	If time_to die = 0 or times_must_eat = 0, do nothing
	If there is only one philo, special case function

	N pairs de philos are thinking and sleeping while others eat
	N impairs de philos are eating, sleeping and thinking
	but if simulation should stop because a philo died, it stops.
*/
void	*p_routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal_time = philo->data->start_time;
	pthread_mutex_unlock(&philo->meal_lock);
	if (philo->data->time_to_die == 0 || \
			philo->data->time_to_eat == 0 || philo->data->times_must_eat == 0)
		return (NULL);
	if (philo->data->n_philos == 1)
		return (one_p_routine(philo));
	if (philo->p_id % 2)
	{
		print(philo, THINKING, 0);
		ft_usleep(philo->data, philo->data->time_to_eat);
	}
	while (simulation_stops_def(philo->data) == 0)
	{
		eating(philo);
		sleeping(philo);
		print(philo, THINKING, 0);
		usleep(50);
	}
	return (NULL);
}

/*
	Get current time at the beginning.

	Philosophers threads:
	1. Create a thread (a philo) n_philos times (from 0 to n_philos - 1); 
	2. Pass the p_routine() function to each;
	3. Pass the "t_philo" structure to each;
 	4. Join all created threads (below).

	Checker thread if a philo died:
	1. Create a checker thread if there are more than 1 philos
   		(1 philo is a special case, dies immediately);
	2. Pass check_routine() function to it;
	3. Pass the "t_data" structure to it.
 	4. Join this thread (below).
*/
int	init_threads_philos_checker(t_data *data)
{
	int	i;

	data->start_time = get_current_time();
	i = 0;
	while (i < data->n_philos)
	{
		if (pthread_create(&data->philosophers[i].p_thread, NULL, &p_routine, \
				&data->philosophers[i]) != 0)
			return (printf(PTHREAD_ERROR), 0);
		i++;
	}
	if (data->n_philos > 1)
		if (pthread_create(&data->checker_thread, NULL, \
					&check_routine, data) != 0)
			return (printf(PTHREAD_ERROR), 0);
	return (1);
}

int	join_threads_philos_checker(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philos)
	{
		if ((pthread_join(data->philosophers[i].p_thread, NULL)) != 0)
			return (printf(PTHREAD_ERROR), 0);
		i++;
	}
	if (data->n_philos > 1)
		if (pthread_join(data->checker_thread, NULL) != 0)
			return (printf(PTHREAD_ERROR), 0);
	return (1);
}
