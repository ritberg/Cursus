#include "stdlib.h"
#include "stdio.h"

int     *ft_range(int start, int end)
{
	int	diff;
	int	i = 0;
	int	*tab;

	if (start < end)
	{
		diff = end - start;
		tab = malloc(sizeof(int) * diff);
		while (i <= diff)
		{
			tab[i] = start;
			i++;
			start++;
		}
	}
	else
	{
		diff = start - end;
		tab = malloc(sizeof(int) * diff);
		while (i <= diff)
		{
			tab[i] = start;
			i++;
			start--;
		}
	}
	return (tab);
}
/*
int	main()
{
	int	start = 0;
	int	end = -3;
	int	diff;
	int	i = 0;
	int	*tab = ft_range(start, end);

	if (start < end)
		diff = end - start;
	else
		diff = start - end;
	while (i <= diff)
	{
		printf("%d\n", tab[i]);
		i++;
	}
	return (0);
}
*/
