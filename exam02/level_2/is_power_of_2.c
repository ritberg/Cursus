#include "stdio.h"

int is_power_of_2(unsigned int n)
{
	int nbr = 1;

	while(nbr <= n)
	{
		if (nbr == n)
			return (1);
		nbr = nbr * 2;
	}
	return (0);
}
/*
int	main()
{
	printf("%d\n", is_power_of_2(1));
	printf("%d\n", is_power_of_2(6));
	return (0);
}
*/
