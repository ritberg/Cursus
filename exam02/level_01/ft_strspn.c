#include "stdio.h"

char	*ft_strchr(const char *accept, int c)
{
	while (*accept)
	{
		if (*accept == c)
			return ((char *)accept);
		accept++;
	}
	return (0);
}

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t i = 0;

	while (s[i])
	{
		if (!ft_strchr(accept, s[i]))
			break;
		i++;
	}
	return (i);
}
/*
int	main()
{
	char	*s = "abcyhj";
	char	*accept = "p[abci";
	printf("%zu\n", ft_strspn(s, accept));
	return (0);
}
*/
