/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:04:54 by mmakarov          #+#    #+#             */
/*   Updated: 2023/04/09 18:28:50 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

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

	int		ok;

}	t_ppx;

int	parsing(t_ppx *ppx, char **argv, char **envp);
void	parent_process(t_ppx *ppx);
int	child2_process(t_ppx *ppx, char **envp);
int	child1_process(t_ppx *ppx, char **envp);
void	pipex(t_ppx *ppx, char **envp);
int	my_perror(const char *str);
int	error_checker(int argc);

#endif
