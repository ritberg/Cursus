#include "stdio.h"

unsigned char	reverse_bits(unsigned char octet)
{
	int		i = 8;
	unsigned char	res = 0;

	while (i > 0)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		i--;
	}
	return (res);
}

int	main()
{
	unsigned char b;

	b = '.';
	printf("%o\n", b);
	printf("%c\n", reverse_bits(b)); // byte 00101110 ('.') is indeed the reverse of byte 01110100 ('t')
	printf("%o\n", reverse_bits(b));
	return (0);
}
