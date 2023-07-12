#include "microshell.h"

t_cmd	*get_cmd(char **argv, int j)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->content = argv[j];
	cmd->next = NULL;
	return (cmd);
}

t_cmd	*list_of_cmd(int argc, char **argv)
{
	t_cmd	*new;
	t_cmd	*tmp;
	int	j;

	j = argc - 1;
	new = NULL;
	while (j >= 1)
	{
		tmp = get_cmd(argv, j);
		tmp->next = new;
		new = tmp;
		j--;
	}
	return (new);
}


/*
void	pipex(t_cmd **head)
{
	int		fd_pipe[2];
	int		save_fdin;
	t_cmd	*cmd;
	int		i;

	while (cmd)
	{
		pipe(fd_pipe);
		cmd->pid = fork();
		if (cmd->pid < 0)
		{
			error_message2("fork:", strerror(errno));
			return ;
		}
		pipex_signal_handler();
		pipex_helper(fd_pipe, cmd, i, &save_fdin);
		cmd = cmd->next;
		i++;
	}
	after_fork(head, i, save_fdin);
*/
int	main(int argc, char **argv, char **env)
{
	int	j;
	t_cmd	*cmd;

	cmd = list_of_cmd(argc, argv);
	while (cmd)
	{
		printf("%s\n", cmd->content);
		cmd = cmd->next;
	}
	/*
	j = 1;
	while (j < argc)
	{
		execve(argv[j], &argv[j], env);
		j++;
	}
	*/
	return (0);
}
