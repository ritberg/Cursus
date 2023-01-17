#include "unistd.h"

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

int	main()
{
	unsigned char o;
	o = 2;
	print_bits(o);
	return (0);
}
