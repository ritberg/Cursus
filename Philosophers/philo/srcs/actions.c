/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:30:12 by mmakarov          #+#    #+#             */
/*   Updated: 2023/07/07 17:33:27 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incls/philo.h"

void	forks_up(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print(philo, FORKS, 0);
	pthread_mutex_lock(philo->l_fork);
	print(philo, FORKS, 0);
}

void	forks_down(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	sleeping(t_philo *philo)
{
	print(philo, SLEEPING, 0);
	ft_usleep(philo->data, philo->data->time_to_sleep);
}

/*
	! last_meal_time = current time
	! without this assignation, a philo dies
	A philo takes forks (right then left), eats, sleeps and drop forks
   		(left then right).
	Get times_ate to know if it should stop when there is the 5th arg.
*/
void	eating(t_philo *philo)
{
	forks_up(philo);
	print(philo, EATING, 0);
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal_time = get_current_time();
	pthread_mutex_unlock(&philo->meal_lock);
	if (simulation_stops_def(philo->data) == 0)
	{
		pthread_mutex_lock(&philo->meal_lock);
		philo->times_ate++;
		pthread_mutex_unlock(&philo->meal_lock);
	}
	ft_usleep(philo->data, philo->data->time_to_eat);
	forks_down(philo);
}
