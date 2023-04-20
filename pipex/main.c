/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 19:44:39 by mmakarov          #+#    #+#             */
/*   Updated: 2023/04/20 15:36:39 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(t_ppx *ppx)
{
	int	status;

	close(ppx->f1);
	close(ppx->f2);
	close(ppx->end[0]);
	close(ppx->end[1]);
	waitpid(ppx->child1, &status, 0);
	waitpid(ppx->child2, &status, 0);
}

int	child2_process(t_ppx *ppx, char **envp)
{
	if (dup2(ppx->f2, STDOUT_FILENO) < 0)
		return (my_perror("Error", ppx));
	if (dup2(ppx->end[0], STDIN_FILENO) < 0)
		return (my_perror("Error", ppx));
	close(ppx->end[1]);
	close(ppx->f2);
	execve(ppx->cmd2, ppx->mycmdargs3, envp);
	free(ppx->cmd2);
	free_tab(ppx->mycmdargs3);
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}

int	child1_process(t_ppx *ppx, char **envp)
{
	if (dup2(ppx->f1, STDIN_FILENO) < 0)
		return (my_perror("Error", ppx));
	if (dup2(ppx->end[1], STDOUT_FILENO) < 0)
		return (my_perror("Error", ppx));
	close(ppx->end[0]);
	close(ppx->f1);
	execve(ppx->cmd1, ppx->mycmdargs2, envp);
	free(ppx->cmd1);
	free_tab(ppx->mycmdargs2);
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}

void	pipex(t_ppx *ppx, char **envp)
{
	pipe(ppx->end);
	ppx->child1 = fork();
	if (ppx->child1 < 0)
		return (perror("Fork: "));
	if (!ppx->child1) //if fork() returns 0, we are in the child1 process
		child1_process(ppx, envp);
	else
	{
		ppx->child2 = fork();
		if (ppx->child2 < 0)
			return (perror("Fork: "));
		if (!ppx->child2)
			child2_process(ppx, envp);
		else
			parent_process(ppx);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_ppx	*ppx;

	ppx = ft_calloc(1, sizeof(t_ppx));
	if (!ppx)
		return (-1);
	if (error_checker(argc, ppx))
		return (-1);
	ppx->f1 = open(argv[1], O_RDONLY);
	ppx->f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (ppx->f1 < 0 || ppx->f2 < 0)
		return (-1);
	if (!parsing_path(ppx, envp))
		return (-1);
	if (!split_paths(ppx))
		return (-1);
	if (!parsing_args(ppx, argv))
		return (-1);
	if (!find_cmd1(ppx))
		return (-1);
	if (!find_cmd2(ppx))
		return (-1);
	pipex(ppx, envp);
	exit(0);
	return (0);
}
