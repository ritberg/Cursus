#include "unistd.h"
#include "stdio.h"

void	ft_write(int repeat_n_times, char c)
{
	while (repeat_n_times >= 0)
	{
		write(1, &c, 1);
		repeat_n_times--;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	ind_ascii;
	int	current_ind;
	int	repeat_n_times;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z') 
			{
				ind_ascii = 'A' + '0';
				current_ind = argv[1][i] + '0';
				repeat_n_times = current_ind - ind_ascii;
				ft_write(repeat_n_times, argv[1][i]);
			}
			else if (argv[1][i] >= 'a' && argv[1][i] <= 'z') 
			{
				ind_ascii = 'a' + '0';
				current_ind = argv[1][i] + '0';
				repeat_n_times = current_ind - ind_ascii;
				ft_write(repeat_n_times, argv[1][i]);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
