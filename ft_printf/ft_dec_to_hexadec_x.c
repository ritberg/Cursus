
#include "ft_printf.h"

void	ft_dec_to_hexadec_x(int i)
{
	int	n;
	char	hexadec[100];
	int	j;
	int	k;

	j = 0;
	while (i != 0)
	{
		n = i % 16;
		if (n < 10)
			hexadec[j++] = n + 48;
		else
			hexadec[j++] = n + 87; //97 - 10 in ascci
		i = i / 16;
	}
	k = j - 1;
	while (k >= 0)
	{
		ft_putchar(hexadec[k]);
		k--;
	}
}
