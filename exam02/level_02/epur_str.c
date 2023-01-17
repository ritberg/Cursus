#include "unistd.h"
#include "stdio.h"

int	main(int argc, char **argv)
{
	int	i;
	int	yes;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		while (argv[1][i])
		{
			if (argv[1][i] == ' ' || argv[1][i] == '\t')
				yes = 1;
			//if (!(argv[1][i] == ' ' || argv[1][i] == '\t'))
			//if (argv[1][i] != ' ' || argv[1][i] != '\t')    dsn't work !!
			else           //else is the best, the clearest
			{
				if (yes)
					write(1, " ", 1);
				yes = 0;
				write(1, &argv[1][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
