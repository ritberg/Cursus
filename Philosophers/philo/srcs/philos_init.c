/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <mmakarov@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:13:42 by mmakarov          #+#    #+#             */
/*   Updated: 2023/07/01 19:15:07 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incls/philo.h"

void	print(t_philo *philo, char *str)
{
	time_t	time;

	pthread_mutex_lock(&philo->data->print_lock);
	time = get_current_time() - philo->data->start_time;
	printf("%ld %d %s", time, philo->p_id + 1, str);
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
	philo->times_ate++;
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

 * when times_ate, incremented in eating(), < times_must_eat(5th arg),
   do the actions "times_must_eat" times

 function too long !! to cut!

*/
void	*p_routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->data->time_to_die == 0 || philo->data->times_must_eat == 0)
		return (NULL);
	pthread_mutex_lock(&philo->eating); //TODO
	philo->start_eating = philo->data->start_time; //compare start_eating with time_to_die 
	pthread_mutex_unlock(&philo->eating); //
	if (philo->data->n_philos == 1)
		return (one_p_routine(philo));
	if (philo->p_id % 2)
		print(philo, THINKING);
	if (philo->data->times_must_eat != NO_FIFTH_ARG)
	{
		while (philo->times_ate < philo->data->times_must_eat)
		{
			eating(philo);
			sleeping(philo);
			print(philo, THINKING);
		}
	}
	else
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
int	init_philos_threads(t_data *data)
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
	i = 0;
	while (i < data->n_philos)
	{
		if ((pthread_join(data->philosophers[i].p_thread, NULL)) != 0)
			return (printf(PTHREAD_ERROR), 0);
		i++;
	}
	return (1);
}
