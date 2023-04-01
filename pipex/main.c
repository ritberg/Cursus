#include "pipex.h"

void    pipex(int f1, int f2)
{
    pipe(end);
    parent = fork();
    if (parent < 0)
         return (perror("Fork: "));
    if (!parent) // if fork() returns 0, we are in the child process
        child_process(f1, cmd1);
    else
        parent_process(f2, cmd2);
}
int	main(int argc, char **argv)
{
	if (error_checker(argc, argv))
		return (0);
	pipex(f1, f2);
	exit(0);
	return (0);
}
