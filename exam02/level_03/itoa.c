#include "stdlib.h"
#include "stdio.h"

int	ft_size(int nbr)
{
	int	size;

	if (nbr == 0)
		return (1);
	if (nbr < 0)
		size = 1;
	else
		size = 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		size++;
	}
	return (size);
}

void	div_mod(int nbr, char *tab, int size)
{
	int	d;

	if (nbr == 0 && tab[0] != '-')
		tab[0] = '0';
	if (nbr < 0)
	{
		nbr = -nbr;
		tab[0] = '-';
	}
	if (nbr > 0)
	{
		div_mod(nbr / 10, tab, size - 1);
		d = nbr % 10 + '0';
		tab[size-1] = d;
	}	
}

char	*ft_itoa(int nbr)
{
	char	*tab;
	int	size;

	size = ft_size(nbr);
	tab = malloc(sizeof(char) * size + 1);
	if (tab == NULL)
		return (NULL);
	div_mod(nbr, tab, size);
	return (tab);
}

int	main()
{
	int	nbr = -123;
	printf("%s\n", ft_itoa(nbr));
	return (0);
}

