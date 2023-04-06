/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:04:54 by mmakarov          #+#    #+#             */
/*   Updated: 2023/04/06 18:36:09 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"

typedef struct s_ppx
{
	pid_t	child1;
	pid_t	child2;
	int		f1;
	int		f2;
	int		end[2];
	char	*cmd1;
	char	*cmd2;

	char	*path_envp;
	char	**mypaths;
	char	**mycmdargs2;
	char	**mycmdargs3;

}	t_ppx;

#endif
