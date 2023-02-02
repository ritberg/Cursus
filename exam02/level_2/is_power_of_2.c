#include "stdio.h"

int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	if (n >= 0 && n % 2 == 0)
	{
		is_power_of_2(n / 2);
		return (1);
	}
	return (0);
}

int	main()
{
	printf("%d\n", is_power_of_2(128));
	printf("%d\n", is_power_of_2(1));
	return (0);
}
