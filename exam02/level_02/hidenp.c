#include "unistd.h"
#include "stdio.h"

/*
int	check(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	if (count > 1)
		return (0);
	return (1);
}
*/

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	ok;
	int	saved_j;
	int	argv1_len;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	j = 0;
	saved_j = 0;
	i = 0;
	argv1_len = ft_strlen(argv[1]);
	ok = 0;
	if (argc == 3)
	{
		while (argv[2][j])
		{
			if (argv[1][i] == argv[2][j] && saved_j <= j)
			{
				ok++;
				saved_j = j;
			//	printf("ok %d\n", ok);
			//	printf("i %d\n", i);
			//	printf("saved_j %d\n", saved_j);
				i++;
				j = -1;
			}
			j++;
		}
	}
	if (ok == argv1_len)
		write(1, "1", 1);
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}
