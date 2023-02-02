#include "unistd.h"

int	main(int argc, char **argv)
{
	char	result;

	if (argc > 1)
	{	
		result = (argc - 1) + '0';
		write(1, &result, 1);
	}
	write(1, "\n", 1);
	return (0);
}
