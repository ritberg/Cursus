#include "pipex.h"
/*
int	parsing(t_ppx *ppx, char **argv, char **envp)
{
	// chercher PATH et recuperer ce qui suit apres PATH=
	int	i;
	int	j;

	j = 0;
	ppx->path_envp = NULL; //protection
	while (envp[j])
	{
		if (ft_strncmp("PATH=", envp[j], 5) == 0)
		{
			ppx->path_envp = envp[j];
			break;
		}
		j++;
	}
	if (!ppx->path_envp)
		return (my_perror("PATH unset"));
	ppx->mypaths = ft_split(ppx->path_envp, ':');
	if (!ppx->mypaths)  //protection
		return (my_perror("Split error"));
	j = 0;
	while (ppx->mypaths[j])
	{
		ppx->mypaths[j] = ft_strjoin(ppx->mypaths[j], "/");
		if (!ppx->mypaths)
			return (my_perror("Strjoin error"));
		j++;
	}
	ppx->mycmdargs2 = ft_split(argv[2],' '); // ex ls -la. what if grep 'a'?
	if (!ppx->mycmdargs2)
		return (my_perror("Split error"));
	ppx->mycmdargs3 = ft_split(argv[3], ' ');
	if (!ppx->mycmdargs3)
		return (my_perror("Split error"));
	j = 0;
	while (ppx->mypaths[j])
	{
		ppx->cmd1 = ft_strjoin(ppx->mypaths[j], ppx->mycmdargs2[0]);
		if (!ppx->cmd1)
			return (my_perror("Strjoin error"));
		ppx->ok = access(ppx->cmd1, F_OK & X_OK);
		if (ppx->ok == 0)
			break;
		j++;
	}
	if (ppx->ok == -1)
		return (my_perror("Error"));
	i = 0;
	while (ppx->mypaths[i])
	{
		ppx->cmd2 = ft_strjoin(ppx->mypaths[i], ppx->mycmdargs3[0]);
		if (!ppx->cmd2)
			return (my_perror("Strjoin error"));
		ppx->ok = access(ppx->cmd2, F_OK & X_OK);
		if (ppx->ok == 0)
			break;
		i++;
	}
	if (ppx->ok == -1)
		return (my_perror("Error"));
	return (0);

	// mycmdargs = commandes trouvees dans /bin
	// cmd1 = path of the first command cat, ex /bin/cat
	// envoyer une erreur si la commande n'est pas valide
}
*/
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
		return (my_perror("Error"));
	if (dup2(ppx->end[0], STDIN_FILENO) < 0)
		return (my_perror("Error"));
	close(ppx->end[1]);
	close(ppx->f2);
	execve(ppx->cmd2, ppx->mycmdargs3, envp);
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}

int	child1_process(t_ppx *ppx, char **envp)
{
	if (dup2(ppx->f1, STDIN_FILENO) < 0)
		return (my_perror("Error"));
	if (dup2(ppx->end[1], STDOUT_FILENO) < 0)
		return (my_perror("Error"));
	close(ppx->end[0]);
	close(ppx->f1);
	execve(ppx->cmd1, ppx->mycmdargs2, envp);
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}

void	pipex(t_ppx *ppx, char **envp)
{
	pipe(ppx->end);
	ppx->child1 = fork();
	if (ppx->child1 < 0)
		return (perror("Fork: "));
	if (!ppx->child1)
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
	
	ppx = malloc(sizeof(t_ppx));
	if (!ppx)
		return (0);
	if (error_checker(argc))
		return (0);
     ppx->f1 = open(argv[1], O_RDONLY);
     ppx->f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
     if (ppx->f1 < 0 || ppx->f2 < 0)
          return (-1);
	 parsing_path(ppx, envp);
	 parsing_args(ppx, argv);
	 find_cmd1(ppx);
	 find_cmd2(ppx);
	 pipex(ppx, envp);
	 exit(0);
	 return (0);
}
