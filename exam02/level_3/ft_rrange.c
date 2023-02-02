#include "stdlib.h"
#include "stdio.h"

int     *ft_rrange(int start, int end)
{
	int	*tab;
	int	diff;
	int	i;

	diff = end - start;
	i = 0;
	tab = malloc(sizeof(int) * diff);
	if (tab == 0)
		return (0);
	while (i <= diff)
	{
		tab[i] = end;
		end--;
		i++;
	}
	return (tab);
}

int	main()
{
	int	start = -2;
	int	end = 3;
	int	diff = end - start;
	int	i = 0;
	int	*tab;

	tab = ft_rrange(start, end);
	while (i <= diff)
	{
		printf("%d\n", tab[i]);
		i++;
	}
	return (0);
}
