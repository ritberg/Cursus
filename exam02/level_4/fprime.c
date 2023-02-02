#include "stdio.h"
#include "stdlib.h"

int	main(int argc, char **argv)
{
	int	n;
	int	d;

	if (argc != 2)
	{
		printf("\n");
		return (0);
	}
	if (argc == 2)
	{
		n = atoi(argv[1]);
		d = 2;
		if (n == 1)
			printf("1");
		while (d <= n)
		{
			if (n % d == 0)
			{
				printf("%d", d);
				if (d == n) //not to print * before \0
					break;
				printf("*");
				n = n / d; // hmm
			//	printf(" n %d\n", n);
			//	printf(" d %d\n", d); //d changes?? 
				d = 1; // hmmm
			}
			d++;
		}
		printf("\n");
	}
	return (0);
}
