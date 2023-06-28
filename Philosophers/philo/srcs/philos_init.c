/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <mmakarov@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:13:42 by mmakarov          #+#    #+#             */
/*   Updated: 2023/06/28 14:24:57 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incls/philo.h"

/* get current time */
time_t	ft_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	*p_routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	printf("haha\n");
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
