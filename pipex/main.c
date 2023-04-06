#include "pipex.h"

int	parsing(t_ppx *ppx, char **argv, char **envp) //
{
	ppx->path_envp = ft_substr(envp, 0, ft_strlen(argv[2]));
	ppx->mypaths = ft_split(ppx->path_envp, ":");
	ppx->mycmdargs = ft_split(argv[2], " ");
}

int	parent_process(t_ppx *ppx, char **argv, char **envp)
{
	int	status;
	int	i;

	waitpid(-1, &status, 0); //
	if (dup2() < 0)
		return (perror("Error"));
	dup2(ppx->f2, STDOUT_FILENO);
	dup2(ppx->end[0], STDIN_FILENO);
	close(ppx->end[1])
	close(ppx->f2);
	exit(EXIT_FAILURE);

	i = -1;
	while (ppx->mypaths[++i]) //
	{
		ppx->cmd2 = ft_join(ppx->mypaths[i], argv[3]);
		exercve(ppx->cmd2, ppx->mycmdargs, envp);
		free(ppx->cmd2);
	}
	return (EXIT_FAILURE);
}

int	child_process(t_ppx *ppx, char **argv, char **envp)
{
	int	i;

	if (dup2() < 0)
		return (perror("Error"));
	dup2(ppx->f1, STDIN_FILENO);
	dup2(ppx->end[1], STDOUT_FILENO);
	close(ppx->end[0]);
	close(ppx->f1);
	exit(EXIT_FAILURE);

	i = -1;
	while (ppx->mypaths[++i]) //
	{
		ppx->cmd1 = ft_join(ppx->mypaths[i], argv[2]);
		exercve(ppx->cmd1, ppx->mycmdargs, envp);
		free(ppx->cmd1);
	}
	return (EXIT_FAILURE);
}

void	pipex(t_ppx *ppx, char **argv, char **envp)
{
	pipe(ppx->end);
	ppx->parent = fork();
	if (ppx->parent < 0)
		return (perror("Fork: "));
	if (!ppx->parent)
		child_process(ppx, argv, envp); //child_process(f1, cmd1)
	else
		parent_process(ppx, argv, envp); //parent_process(f2, cmd2)
}

int	main(int argc, char **argv, char **envp)
{
	t_ppx	*ppx;
	
	ppx = malloc(sizeof(t_ppx));
	if (error_checker(argc, argv))
		return (0);
     ppx->f1 = open(argv[1], O_RDONLY);
     ppx->f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
     if (ppx->f1 < 0 || ppx->f2 < 0)
          return (-1);
	 parsing(ppx, char **argv, char **envp);
	 pipex(ppx, argv, envp);
	 exit(0);
	 return (0);
}
