#include "stdio.h"

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;
	size_t	j;
	size_t	res;

	i = 0;
	j = 0;
	res = 0;
	while (accept[j])
	{
		while (s[i])
		{
			if (s[i] == accept[j])
				res++;
			i++;
		}
		j++;
	}
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	main()
{
	char *s = "abc def bnh def m";
	char *accept = "def";
	printf("%zu\n", ft_strspn(s, accept));
	return (0);
}
