#include "unistd.h"
#include "stdio.h"

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	j = 1;

	if (argc <= 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (j < argc)
	{
		i = 0;
		while (argv[j][i])
		{
			if (argv[j][i] >= 'A' && argv[j][i] <= 'Z')
				argv[j][i] += 32;
			if ((i == 0 && argv[j][i] >= 'a' && argv[j][i] <= 'z') || (argv[j][i-1] == ' ' || argv[j][i-1] == '\t') \
					&& argv[j][i] >= 'a' && argv[j][i] <= 'z')
				argv[j][i] -= 32;
			write(1, &argv[j][i], 1);
			i++;
		}
		j++;
		write(1, "\n", 1);
	}
	return (0);
}

/* github

void	str_capitalizer(char *str)
{
	int i = 0;

	if (str[i] >= 'a' && 'z' >= str[i])
		str[i] -= 32;
	write(1, &str[i], 1);
	while (str[++i])
	{
		if (str[i] >= 'A' && 'Z' >= str[i])
			str[i] += 32;
		if ((str[i] >= 'a' && 'z' >= str[i]) && (str[i - 1] == ' ' || \
		str[i - 1] == '\t'))
			str[i] -= 32;
		write(1, &str[i], 1);
	}
}

int main(int argc, char *argv[])
{
	int i;

	if (argc < 2)
		write(1, "\n", 1);
	else
	{
		i = 1;
		while (i < argc)
		{
			str_capitalizer(argv[i]);
			write(1, "\n", 1);
			i += 1;
		}
	}
	return (0);
}
*/
