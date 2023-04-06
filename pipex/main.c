#include "pipex.h"

int	parsing(t_ppx *ppx, char **argv, char **envp)
{
	// chercher PATH et recuperer ce qui suit, variable p
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (envp[j++][i])
	{
		while (envp[j][i++])
			ppx->path_envp = ft_strncmp("PATH=", envp[j][i], 5);
	}
	ppx->mypaths = ft_split(ppx->path_envp, ":");
	mycmdargs2 = ft_split(argv[2], " "); // ex ls -la. what if grep 'a'?
	mycmdargs3 = ft_split(argv[3], " ");
	i = 0;
	j = 0;
	while (mypaths[j++][i])
	{
		while (mypaths[j][i++])
			ppx->cmd1 = // voir la fonction access() pour acceder aux commandes dans les dossiers
	}
	// mycmdargs = commandes trouvees dans /bin
	// cmd1 = path of the first command cat, ex /bin/cat
	// envoyer une erreur si la commande n'est pas valide
}

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
		return (perror("Error"));
	if (dup2(ppx->end[0], STDIN_FILENO) < 0)
		return (perror("Error"));
	close(ppx->end[1])
	close(ppx->f2);
	exercve(ppx->cmd2, ppx->mycmdiargs3, envp);
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}

int	child1_process(t_ppx *ppx, char **envp)
{
	if (dup2(ppx->f1, STDIN_FILENO) < 0)
		return (perror("Error"));
	if (dup2(ppx->end[1], STDOUT_FILENO) < 0)
		return (perror("Error"));
	close(ppx->end[0]);
	close(ppx->f1);
	exercve(ppx->cmd1, ppx->mycmdiargs2, envp);
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
	if (error_checker(argc, argv))
		return (0);
     ppx->f1 = open(argv[1], O_RDONLY);
     ppx->f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
     if (ppx->f1 < 0 || ppx->f2 < 0)
          return (-1);
	 parsing(ppx, argv, envp);
	 pipex(ppx, envp);
	 exit(0);
	 return (0);
}
