#include "stdlib.h"
#include "stdio.h"

int     *ft_range(int start, int end)
{
	int	*ptr;
	int	diff;
	int	i;

	diff = end - start;
	ptr = malloc(sizeof(int) * diff);
	if (ptr == 0)
		return (0);
	i = 0;
	while (i <= diff)
	{
		ptr[i] = start;
		start++;
		i++;
	}
	return (ptr);
}

int	main()
{
	int	start = 5;
	int	end = 9;
	int	i = 0;
	int	*tab = ft_range(start, end);
	while (i <= (end - start))
	{
		printf("%d\n", tab[i]);
		i++;
	}
	return (0);
}
