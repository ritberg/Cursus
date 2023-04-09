/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:04:54 by mmakarov          #+#    #+#             */
/*   Updated: 2023/04/09 19:19:08 by mmakarov         ###   ########.fr       */
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
	int		j;

}	t_ppx;

//errors
int	my_perror(const char *str);
int	error_checker(int argc);

//parsing
int	parsing_path(t_ppx *ppx, char **envp);
int	parsing_args(t_ppx *ppx, char **argv);
int	find_cmd1(t_ppx *ppx);
int	find_cmd2(t_ppx *ppx);

//pipes
void	parent_process(t_ppx *ppx);
int	child2_process(t_ppx *ppx, char **envp);
int	child1_process(t_ppx *ppx, char **envp);
void	pipex(t_ppx *ppx, char **envp);

#endif
