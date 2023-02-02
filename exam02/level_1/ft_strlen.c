//#include "stdio.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
/*
int	main()
{
	char *str = "Salut";
	printf("%d\n", ft_strlen(str));
	return (0);
}
*/
