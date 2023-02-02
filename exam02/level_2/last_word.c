#include "unistd.h"
#include "stdio.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
			i++;
		//printf("%d\n", i);
		i -= 1;
		while (i >= 0 && (argv[1][i] == ' ' || argv[1][i] == '\t'))
			i--;
		while (i >= 0 && argv[1][i] != ' ' && argv[1][i] != '\t')
			i--;
		i += 1;
		while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
		{
			write(1, &argv[1][i], 1);
			i++;
		}

	}
	write(1, "\n", 1);
	return (0);
}
