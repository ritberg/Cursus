#include "unistd.h"
#include "stdio.h"

int	check(char *str, char c, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	if (argc == 3)
	{
		while (argv[1][i])
			i++;
		while (argv[2][j])
		{
			argv[1][i] = argv[2][j];
			i++;
			j++;
		}
		i -= 1; //needed?
		k = 0;
		while (k < i)
		{
			if (!check(argv[1], argv[1][k], k))
				write(1, &argv[1][k], 1);
			k++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
