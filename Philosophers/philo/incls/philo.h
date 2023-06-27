/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <mmakarov@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:13:06 by mmakarov          #+#    #+#             */
/*   Updated: 2023/06/27 19:16:53 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <limits.h>
# include <time.h>
# include <stdlib.h>

# define ARGS_NUMBER 		1
# define NOT_DIGIT			2
# define N_PHILOS			3
# define BIGGER_THAN_INTMAX	-1
# define NO_FIFTH_ARG		-2

# define MALLOC_ERROR	"malloc error!\n"
# define PTHREAD_ERROR	"pthread error!\n"

typedef struct s_philo
{
	pthread_t		p_thread;
	int				p_id;
//	int				fork[2]; //or separately left and right ?
	pthread_mutex_t	*l_fork;/////
	pthread_mutex_t	*r_fork;//////
	time_t			last_eating_time;
	int				times_ate;
}	t_philo;

typedef struct s_data
{
	time_t			start_time;
	int				n_philos;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				times_must_eat;
	t_philo			**philosophers;
	pthread_mutex_t	*forks;  //
	pthread_mutex_t	print_lock;
}	t_data;

/****************************
          utils.c
****************************/
int	ft_atoi(char *str);
int	is_digit(char *str);

/****************************
      structures_init.c
****************************/
t_data	*init_data_structure(int argc, char **argv);
t_philo	**init_philo_structure(t_data *data);

/****************************
      errors_frees.c
****************************/
void	free_structures(t_data *data);
int		error_message(int flag);


#endif
