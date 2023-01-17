#include "stdio.h"

int	max(int* tab, unsigned int len)
{
	int	i;
	int	max;

	if (len == 0 || !tab)
		return (0);
	i = 0;
	max = tab[i];
	while (i < len)
	{
		if (max < tab[i])
			max = tab[i];
		i++;
	}
	return (max);
}

int	main()
{
	int	tab[4];
	tab[0] = 0;
	tab[1] = 7;
	tab[2] = 25;
	tab[3] = 3;
	printf("%d\n", max(tab, 4));
	return (0);
}
