#include "stdlib.h"
#include "stdio.h"

int	main(int argc, char **argv)
{
	int	a;
	int	b;
	int	n;

	if (argc != 3)
	{
		printf("\n");
		return (0);
	}
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	if (argc == 3)
	{
		if (a > b)
			n = b;
		else
			n = a;
		while (n > 0)
		{
			if (a % n == 0 && b % n == 0)
			{
				printf("%d\n", n);
				break;
			}
			n--;
		}
	}
	return (0);
}
