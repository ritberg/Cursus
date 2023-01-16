#include "unistd.h"

int	is_doublon(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (0);
		str++;
	}
	return (1);
}


int	main(int argc, char **argv)
{
	int	i;
	int	j;
	char	c;

	i = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			j = 0;
			while (argv[2][j])
			{
				if (argv[1][i] == argv[2][j])
				{
					c = argv[1][i];
					if (!(is_doublon(argv[1], c)) || !(is_doublon(argv[2], c)))
						write(1, &c, 1);
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
