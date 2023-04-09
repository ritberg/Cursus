/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:23:03 by mmakarov          #+#    #+#             */
/*   Updated: 2023/04/09 18:29:08 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	my_perror(const char *str)
{
	perror(str);
	return (EXIT_FAILURE);
}

int	error_checker(int argc)
{
	if (argc != 5)
		return (my_perror("Args problem"));
	return (EXIT_SUCCESS);
}
