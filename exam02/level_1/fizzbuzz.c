#include "unistd.h"
/* dsn't work
void	ft_putnbr(int i)
{
	char	c;

	if (i >= 10)
	{
		ft_other(i / 10);
		ft_other(i % 10);
	}
	c = i + '0';
	write(1, &c, 1);
}
*/
void	ft_putnbr_small(int i)
{
	char	first;
	char	second;

	if (i > 10)
	{
		first = (i / 10) + '0';
		write(1, &first, 1);
	}
	second = (i % 10) + '0';
	write(1, &second, 1);
}

int	main()
{
	int	i;

	i = 1;
	while (i <= 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else
			ft_putnbr_small(i);
			//ft_putnbr(i);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
