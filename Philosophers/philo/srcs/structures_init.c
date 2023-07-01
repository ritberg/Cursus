/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <mmakarov@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:08:02 by mmakarov          #+#    #+#             */
/*   Updated: 2023/07/01 19:01:26 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incls/philo.h"

/* the idea is to treat separately the case of the philo[0] (n_philo = 1):
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
		philosophers[i].start_eating = 0;
		philosophers[i].times_ate = 0;
		philosophers[i].dead = 0;
		philosophers[i].data = data;
		i++;
	}
	pthread_mutex_init(&philosophers->eating, NULL);
	return (philosophers);
}

t_data	*init_data_structure(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (printf(MALLOC_ERROR), NULL);
	data->start_time = 0;
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
	return (data);
}
