//#include "stdio.h"

int    ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
/*
int	main()
{
	char *s1 = "Salut ciao";
	char *s2 = "Salut, mes amis";
	printf("%d\n", ft_strcmp(s1, s2));
	return (0);
}
*/
