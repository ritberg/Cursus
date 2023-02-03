#include "stdlib.h"
#include "stdio.h"

int     *ft_rrange(int start, int end)
{
	int	i;
	int	diff;
	int	*tab;

	i = 0;
	if (start > end)
	{
		diff = start - end;
		tab = malloc(sizeof(int) * diff);
		if (tab == 0)
			return (0);
		while (i <= diff)
		{
			tab[i] = end;
			i++;
			end++;
		}
	}
	else
	{
		diff = end - start;
		tab = malloc(sizeof(int) * diff);
		if (tab == 0)
			return (0);
		while (i <= diff)
		{
			tab[i] = end;
			i++;
			end--;
		}
	}
	return (tab);
}
/*
int	main()
{
	int	start = 0;
	int end = -3;
	int	 i = 0;
	int	*tab = ft_rrange(start, end);
	int	diff;

	if (start > end)
		diff = start - end;
	else
		diff = end - start;
	while (i <= diff)
	{
		printf("%d\n", tab[i]);
		i++;
	}
	return (0);
}
*/
