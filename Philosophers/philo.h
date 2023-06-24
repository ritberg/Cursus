/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <mmakarov@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:13:06 by mmakarov          #+#    #+#             */
/*   Updated: 2023/06/24 18:16:56 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <limits.h>

# define ARGS_NUMBER 		1
# define NOT_DIGIT			2
# define N_PHILOS			3
# define BIGGER_THAN_INTMAX	-1

/****************************
          utils.c
****************************/
int	ft_atoi(char *str);
int	is_digit(char *str);

#endif
