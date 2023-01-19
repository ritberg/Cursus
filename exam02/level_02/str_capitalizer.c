#include "unistd.h"

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < argc)
	{
		while (argv[j][i])
		{
			if (argv[j][i] >= 'A' && argv[j][i] <= 'Z')
			{
				
			}
			i++;
		}
		j++;
	}
	write(1, "\n", 1);
	return (0);
}
