#include "unistd.h"


int	main(int argc, char **argv)
{
	int	i;
	int	ind_diff;
	int	ind_output_maj;
	int	ind_output_min;
	char	c;

	i = 0;
	ind_output_maj = 'Z' + '0';
	ind_output_min = 'z' + '0';
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] >= 'A'&& argv[1][i] <= 'Z')
			{
				ind_diff = (argv[1][i] + '0') - ('A' + '0');
				c = (ind_output_maj - ind_diff) - '0';
				write(1, &c, 1);
			}
			else if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			{
				ind_diff = (argv[1][i] + '0') - ('a' + '0');
				c = (ind_output_min - ind_diff) - '0';
				write(1, &c, 1);
			}
			else
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
