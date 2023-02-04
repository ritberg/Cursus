#include "unistd.h"
#include "stdlib.h"


int	main(int argc, char **argv)
{
	int	i = 0;

	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == '_')
			{
				i += 1;
				argv[1][i] -= 32;
			}
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}



/*
int	main(int argc, char **argv)
{
	int	i;
	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] != '_')
				write(1, &argv[1][i], 1);
			else
			{
				i += 1;
				argv[1][i] -= 32;
				write(1, &argv[1][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
*/


/*
int	main(int argc, char **argv)
{
	int	i;
	int	j;
	char	*new_str;
	int	underscores;

	i = 0;
	underscores = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == '_')
				underscores++;
			i++;
		}
		new_str = malloc(sizeof(char) * (i - underscores + 1));
		if (new_str == 0)
			return (0);
		i = 0;
		j = 0;
		while (new_str[j] && argv[1][i])
		{
			if (argv[1][i] != '_')
				new_str[j] = argv[1][i];
			else
				new_str[j] = argv[1][i + 1] - 32;
			i++;
			j++;
		}
		write(1, new_str, 1);

	}
	write(1, "\n", 1);
	return (0);
}
*/

