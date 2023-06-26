/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <mmakarov@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:08:02 by mmakarov          #+#    #+#             */
/*   Updated: 2023/06/26 19:22:16 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//ft_forks

t_philo	**init_philo_structure(t_data *data)
{
	t_philo	**philosophers;
	int		i;

	i = 0;
	philosophers = malloc(sizeof(t_philo) * data->n_philos);
	if (!philosophers)
		return (printf(MALLOC_ERROR), NULL);
	while (i < data->n_philos)
	{
		philosophers[i] = malloc(sizeof(t_philo));
		if (!philosophers[i])
			return (printf(MALLOC_ERROR), NULL);
		philosophers[i]->p_id = i;
		philosophers[i]->times_ate = 0;
		philosophers[i]->last_eating_time = 0;
	//	ft_forks(philosophers[i]);
		i++;
	}
	return (philosophers);
}

t_data	*init_data_structure(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (printf(MALLOC_ERROR), NULL);
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
	return (data);
}
