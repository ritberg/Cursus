#include "unistd.h"
#include "stdlib.h"
#include "stdio.h"
/*
int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
*/

int	main(int argc, char **argv)
{
	int	size;
	int	start;
	int	end;
	int	final_space;

	size = 0;
	if (argc == 2)
	{
		while (argv[1][size])
			size++;
		while (size >= 0)
		{
			while (argv[1][size] == '\0' || argv[1][size] == ' ' || argv[1][size] == '\t')
				size--;
			end = size;
			while (argv[1][size] && argv[1][size] != ' ' && argv[1][size] != '\t')
				size--;
			start = size + 1;
			//printf("%d\n", start);
			final_space = start;
			while (start <= end)
			{
				write(1, &argv[1][start], 1);
				start++;
			}
			//printf("%d\n", start);
			if (final_space != 0)
				write(1, " ", 1);
		//	size -= 2;
		}
	}
	write(1, "\n", 1);
	return(0);
}
