//#include "stdio.h"

void	ft_swap(int *a, int *b)
{
	int	i;
	
	i = *a;
	*a = *b;
	*b = i;
}
/*
int	main()
{
	int a = 3;
	int b = 2;

	printf("%d%d\n", a, b);
	ft_swap(&a, &b);
	printf("%d%d\n", a, b);
	return (0);
}
*/
