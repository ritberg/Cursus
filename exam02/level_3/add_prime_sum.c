#include "unistd.h"
#include "stdio.h"

int	atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\f' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);

}

void	putnbr(int nb)
{
	char 	c;

	if (nb > 9)
	{
		putnbr(nb / 10);
		putnbr(nb % 10);
	}
	else
	{
		c = nb + '0';
		write(1, &c, 1);
	}
}

int	main(int argc, char **argv)
{
	int	n;
	int	i;
	int	res;
	int	c;

	res = 0;
	if (argc == 1)
	{
		write(1, "0\n", 2);
		return (0);
	}
	if (argc == 2)
	{
		n = atoi(argv[1]);
		while (n > 0)
		{
			i = 1;
			c = 0;
			while (i <= n)
			{
				if (n % i == 0)
					c++;
				i++;
			}
			if (c == 2)
				res = res + n;
			n--;
		}
	//	printf("%d res\n", res);
		putnbr(res);
	}
	write(1, "\n", 1);
	return (0);
}
