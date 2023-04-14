/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:04:54 by mmakarov          #+#    #+#             */
/*   Updated: 2023/04/14 11:00:46 by mmakarov         ###   ########.fr       */
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
int		my_perror(const char *str, t_ppx *ppx);
void	free_tab(char **tab);
int		error_checker(int argc, t_ppx *ppx);

//parsing
int		parsing_path(t_ppx *ppx, char **envp);
int		split_paths(t_ppx *ppx);
int		parsing_args(t_ppx *ppx, char **argv);
int		find_cmd1(t_ppx *ppx);
int		find_cmd2(t_ppx *ppx);

//pipes
void	parent_process(t_ppx *ppx);
int		child2_process(t_ppx *ppx, char **envp);
int		child1_process(t_ppx *ppx, char **envp);
void	pipex(t_ppx *ppx, char **envp);

//complicated split
char	**ft_fill_big_table(char *src, char c, char **dst, int *lens);
int		ft_n_words(char *str, char c);
int		*ft_len_strs(char *str, char c, int count, int index);
char	**ft_free_split(char **dst, size_t i);
char	**ft_splitpath(char *s, char c);

#endif
