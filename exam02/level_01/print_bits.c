#include "unistd.h"


/*
void	print_bits(unsigned char octet)
{
	int	i;
	unsigned char	res;

	i = 8;
	res = 0;
	while (octet >= 0 && i > 0)
	{
		res = (res * 2) + (octet % 2);
		octet = octet / 2;
		write(1, &res, 1);
		i--;
	}
}
*/

void print_bits(unsigned char octet)
{
	int		bit;
	char	c;
	bit = 128;
	while (bit > 0)
	{
		if (octet < bit)
		{
			c = '0';
			bit = bit / 2;
			write(1, &c, 1);
		}
		else
		{
			c = '1';
			write(1, &c, 1);
			octet = octet - bit;
			bit = bit / 2;
		}
	}
}

int	main()
{
	unsigned char o;
	o = 117;
	print_bits(o);
	return (0);
}
