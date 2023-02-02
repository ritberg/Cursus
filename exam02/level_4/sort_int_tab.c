#include "stdio.h"

/*   OPTION 1

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i+1])
		{
			ft_swap(&tab[i], &tab[i+1]);  // & to save changes!
			i = 0;
		}
		else
			i++;
	}
}
*/

// OPTION 2


void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	int	c;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i+1])
		{
			c = tab[i];
			tab[i] = tab[i+1];
			tab[i+1] = c;
			i = 0;
		}
		else
			i++;
	}
}


int	main()
{
	int	tab[3];
	tab[0] = 1;
	tab[1] = 2;
	tab[2] = -4;

	sort_int_tab(tab, 3);

	printf("%d\n", tab[0]);
	printf("%d\n", tab[1]);
	printf("%d\n", tab[2]);
	return (0);
}
