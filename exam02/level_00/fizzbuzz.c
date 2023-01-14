#include "unistd.h"
/* dsn't work
void	ft_other(int i)
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
void	ft_other_lu(int i)
{
	int	first;
	int	snd;

	first = i / 10;
	snd = i % 10;
	first = first + '0';
	snd = snd + '0';
	if (i >= 10)
		write(1, &first, 1);
	write(1, &snd, 1);
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
			ft_other_lu(i);
			//ft_other(i);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
