/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <mmakarov@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:08:02 by mmakarov          #+#    #+#             */
/*   Updated: 2023/07/08 13:36:16 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incls/philo.h"

/* 
	Initializing the forks. 
	There are the same number of forks as the philosohers. Init in a while loop.
	from 0 to n_philos-1

	Attributing forks to philos.
	The idea is to always treat separately the case of the philo[0] (n_philo = 1):
	philo[0] takes the fork 0 on his left and n_philos - 1 on his right.
 	other philos take the bigger fork on their left, the smaller on their right
 */

static	pthread_mutex_t	*init_forks(t_data *data)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = malloc(sizeof(pthread_mutex_t) * data->n_philos);
	if (!forks)
		return (printf(PTHREAD_ERROR), NULL);
	i = 0;
	while (i < data->n_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	i = 0;
	data->philosophers[0].l_fork = &forks[0];
	data->philosophers[0].r_fork = &forks[data->n_philos - 1];
	i = 1;
	while (i < data->n_philos)
	{
		data->philosophers[i].l_fork = &forks[i];
		data->philosophers[i].r_fork = &forks[i - 1];
		i++;
	}
	return (forks);
}

/* 
	Malloc "philosophers" data structure for n_philos philosophers
	For each philo from 0 to n_philo-1 initialize all necessary params
	inclunding "data" structure and mutexes meal_lock
 	! Initialize last_meal_time to start_time,
  	got with get_current_time()
*/
t_philo	*init_philo_structure(t_data *data)
{
	t_philo	*philosophers;
	int		i;

	i = 0;
	philosophers = malloc(sizeof(t_philo) * data->n_philos);
	if (!philosophers)
		return (printf(MALLOC_ERROR), NULL);
	while (i < data->n_philos)
	{
		philosophers[i].p_id = i;
		philosophers[i].last_meal_time = data->start_time;
		philosophers[i].times_ate = 0;
		philosophers[i].data = data;
		pthread_mutex_init(&philosophers[i].meal_lock, NULL);
		i++;
	}
	return (philosophers);
}

/*
	Malloc of "data" structure
   	Initialize key 4 or 5 params (time_to...)
   	Initialize dead = 0 (a propri a philo is alive)
   	! Initialize start time with get_current_time()
   	Init forks, "philosophers" structure, mutexes
*/
t_data	*init_data_structure(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (printf(MALLOC_ERROR), NULL);
	data->start_time = get_current_time();
	data->dead = 0;
	data->n_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->times_must_eat = NO_FIFTH_ARG;
	if (argc - 1 == 5)
		data->times_must_eat = ft_atoi(argv[5]);
	data->philosophers = init_philo_structure(data);
	if (!data->philosophers)
		return (printf(MALLOC_ERROR), NULL);
	data->forks = init_forks(data);
	if (!data->forks)
		return (printf(PTHREAD_ERROR), NULL);
	pthread_mutex_init(&data->print_lock, NULL);
	pthread_mutex_init(&data->stop_lock, NULL);
	return (data);
}
