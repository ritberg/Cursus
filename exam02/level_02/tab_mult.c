#include "unistd.h"
#include "stdio.h"

void	small_putnbr(int i)
{
	char	right_c;

	if (i > 9)
	{
		small_putnbr(i / 10);
		small_putnbr(i % 10);
	}
	else
	{
		right_c = i + '0';
		write(1, &right_c, 1);
	}
}

int	mini_atoi(char *str)
{

	int	result;
	int	i;

	result = 0;
	i = 0;
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

int	main(int argc, char **argv)
{
	int	middle;
	int	left;
	int	right;
	char	left_c;

	left = 1;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (argc == 2)
	{
		middle = mini_atoi(argv[1]);
		while (left <= 9)
		{
			left_c = left + '0';
			write(1, &left_c, 1);
			write(1, " x ", 3);
			small_putnbr(middle);
			write(1, " = ", 3);
			right = left * middle;
			small_putnbr(right);
			write(1, "\n", 1);
			left++;
		}
	}
	return (0);
}
