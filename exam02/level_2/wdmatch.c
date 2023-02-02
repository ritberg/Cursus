#include "unistd.h"
#include "stdio.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_strlen(char *str)
{
	int	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argc == 3)
	{
		while (argv[2][j])
		{
			if (argv[2][j] == argv[1][i])
			{
				i++;
			}
			j++;	
		}
		if (ft_strlen(argv[1]) == i) // !
			ft_putstr(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}
