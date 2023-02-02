#include "stdio.h"
#include "stdlib.h"

int	main(int argc, char **argv)
{
	int	first_n;
	int	second_n;
	int	result;

	result = 0;
	if (argc == 4)
	{
		first_n = atoi(argv[1]);
		second_n = atoi(argv[3]);
		if (argv[2][0] == '+')
			result = first_n + second_n;
		else if (argv[2][0] == '-')
			result = first_n - second_n;
		else if (argv[2][0] == '*')
			result = first_n * second_n;
		else if (argv[2][0] == '/')
			result = first_n / second_n;
		else if (argv[2][0] == '%')
			result = first_n % second_n;
		printf("%d\n", result);
	}
	return (0);
}
