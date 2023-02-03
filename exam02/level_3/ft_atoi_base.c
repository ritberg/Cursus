#include "stdio.h"
#include "stdlib.h"

int	ft_isspace(const char c)
{
	if (c == '\n' || c == '\t' || c == '\v' || c == '\r' || c == '\f')
		return (1);
	return (0);
}

int	base(char c, int base)
{
	char *str = "0123456789abcdef";
	char *str2 = "0123456789ABCDEF";
	int	 i = 0;

	while (i < base)
	{
		if (c == str[i] || c == str2[i])
			return (i);
		i++;
	}
	return (-1);

}

int	ft_atoi_base(const char *str, int str_base)
{
	int	res;
	int	i;
	int	sign;

	res = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}

	while (base(str[i], str_base) != -1)
	{
		res = res * str_base;
		res = res + base(str[i], str_base);
		i++;
	}
	return (res * sign);
}
/*
int	main()
{
	printf("%d\n", ft_atoi_base("Ceci permet de decouvrir le fonctionnement de ton ft_atoi_base.", atoi("16")));
	return (0);
}
*/
