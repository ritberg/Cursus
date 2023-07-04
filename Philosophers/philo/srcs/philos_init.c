/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <mmakarov@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:13:42 by mmakarov          #+#    #+#             */
/*   Updated: 2023/07/04 20:05:54 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incls/philo.h"

// check unused variables !


int	simulation_stops_def(t_data *data);

void	print(t_philo *philo, char *str)
{
	time_t	time;

	pthread_mutex_lock(&philo->data->print_lock);
	time = get_current_time() - philo->data->start_time;
	printf("%ld %d %s", time, philo->p_id + 1, str);
	pthread_mutex_unlock(&philo->data->print_lock);
}


/////////////////////////////////////////////////////////////////

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

int	is_dead(t_philo *philo)
{
	if ((get_current_time() - philo->last_meal_time) \
			>= philo->data->time_to_die)
	{
		simulation_stops(philo->data, 1);
	//	printf("last meal time %ld\n", philo->last_meal_time);
	//	printf("time_to_die %ld\n", philo->data->time_to_die);
		print(philo, DIED);
		pthread_mutex_unlock(&philo->meal_lock);
		return (1);
	}
	return (0);
}

/*
   check 5th arg if there is any and check if a philo is dead
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

void	*check_routine(void *ptr)
{
	t_data	*data;

	data = (t_data *)ptr;
	simulation_stops(data, 0);
	while (1)
	{
		if (end(data) == 1)
			return (NULL); // exit marche mais interdit
		usleep(1000);
	}
	return (NULL);
}
///////////////////////////////////////////////////////



void	forks_up(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print(philo, FORKS);
	pthread_mutex_lock(philo->l_fork);
	print(philo, FORKS);
}

void	forks_down(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	sleeping(t_philo *philo)
{
	print(philo, SLEEPING);
	ft_usleep(philo->data->time_to_sleep);
}

void	eating(t_philo *philo)
{
	forks_up(philo);
	pthread_mutex_lock(&philo->data->lock);
	print(philo, EATING);
	pthread_mutex_lock(&philo->meal_lock);/////////////
	philo->last_meal_time = get_current_time();///////////
	pthread_mutex_unlock(&philo->meal_lock);///////////
	if (simulation_stops_def(philo->data) == 0)
	{
		pthread_mutex_lock(&philo->meal_lock);
		philo->times_ate++;
		pthread_mutex_unlock(&philo->meal_lock);
	}
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->data->lock);
	forks_down(philo);
}

void	*one_p_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print(philo, FORKS);
	ft_usleep(philo->data->time_to_die);
	print(philo, DIED);
	pthread_mutex_unlock(philo->r_fork);
	return (NULL);
}

/* the function that is applied to each philosopher thread
 * if time_to die = 0 or if (times_must_eat = 0, rien se passe

*/
void	*p_routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	pthread_mutex_lock(&philo->meal_lock);/////////////
	philo->last_meal_time = philo->data->start_time;///////////
	pthread_mutex_unlock(&philo->meal_lock);///////////
	if (philo->data->time_to_die == 0 || philo->data->times_must_eat == 0)
		return (NULL);
	if (philo->data->n_philos == 1)
		return (one_p_routine(philo));
	if (philo->p_id % 2)
	{
		print(philo, THINKING);
		ft_usleep(philo->data->time_to_eat);
	}
	while (simulation_stops_def(philo->data) == 0)
	{
		eating(philo);
		sleeping(philo);
		print(philo, THINKING);
	}
	return (NULL);
}

/* 
 * create a thread (a philo) n_philos times (from 0 to n_philos - 1); 
   pass the t_philo data structure to each;
   join all created threads.
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
