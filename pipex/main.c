#include "pipex.h"

void    pipex(int f1, int f2)
{
    int	nbytes;
	char	*string = "Hello\n";
	char	readbuffer[80];

	pipe(end);
    parent = fork();
    if (parent == -1)
         return (perror("Fork: "));
    if (parent == 0)
	{
		close(end[0]);
		write(end[1], string, (strlen(string)+1));
	}
    else
	{
		close(end[1]);
		nbytes = read(end[0], readbuffer, sizeof(readbuffer));
	}
}
int	main(int argc, char **argv)
{
	if (error_checker(argc, argv))
		return (0);
     f1 = open(argv[1], O_RDONLY);
     f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
     if (f1 < 0 || f2 < 0)
          return (-1);
	pipex(f1, f2);
	exit(0);
	return (0);
}
