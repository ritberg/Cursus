/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <mmakarov@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:13:42 by mmakarov          #+#    #+#             */
/*   Updated: 2023/06/30 12:29:34 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incls/philo.h"

void	print(t_philo *philo, char *str)
{
	printf("%ld %d %s\n", ft_time() - philo->data->start_time, \
			philo->p_id + 1, str);
}

/* dsnt work. philos id. data race? mutex problem? wrong structure? */
void	*p_routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	pthread_mutex_lock(&philo->data->print_lock);
	print(philo, "is eating?");
	pthread_mutex_unlock(&philo->data->print_lock);
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
