/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <mmakarov@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:13:42 by mmakarov          #+#    #+#             */
/*   Updated: 2023/06/30 17:05:57 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incls/philo.h"

void	ft_usleep(int ms)
{
	struct timeval start;
	struct timeval now;
	
	gettimeofday(&start, 0);
	gettimeofday(&now, 0);
	while (((now.tv_sec - start.tv_sec) * \
			   	1000 + (now.tv_usec - start.tv_usec) / 1000) < ms)
	{
		usleep(10);
		gettimeofday(&now, 0);
	}
}

void	print(t_philo *philo, char *str)
{
	time_t	time;

	pthread_mutex_lock(&philo->data->print_lock);
	time = ft_time() - philo->data->start_time;
	printf("%ld %d %s\n", time, philo->p_id + 1, str);
	pthread_mutex_unlock(&philo->data->print_lock);
}

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
	print(philo, SLEEPING);
	ft_usleep(philo->data->time_to_sleep);
}

void	eating(t_philo *philo)
{
	forks_up(philo);
	pthread_mutex_lock(&philo->data->lock);
	print(philo, EATING);
	philo->times_ate++;
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->data->lock);
	forks_down(philo);
}

/* the function that is applied to each philosopher thread */
void	*p_routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->p_id % 2)
		print(philo, THINKING);
	eating(philo);
	print(philo, THINKING);
	return (NULL);
}

/* create a thread (a philo) n_philos times (from 0 to n_philos - 1); 
   pass the t_philo data structure to each;
   join all created threads.
*/
int	init_philos_threads(t_data *data)
{
	int	i;

	data->start_time = ft_time();
	i = 0;
	while (i < data->n_philos)
	{
		if (pthread_create(&data->philosophers[i].p_thread, NULL, &p_routine, \
				&data->philosophers[i]) != 0)
			return (printf(PTHREAD_ERROR), 0);
		i++;
	}
	i = 0;
	while (i < data->n_philos)
	{
		if ((pthread_join(data->philosophers[i].p_thread, NULL)) != 0)
			return (printf(PTHREAD_ERROR), 0);
		i++;
	}
	return (1);
}
