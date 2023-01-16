#include "stdio.h"

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (reject[j])
	{
		while (s[i])
		{
			if (s[i] == reject[j])
				return (i);
			i++;
		}
		j++;
	}
	if (i > j) //return index of the first \0. may be it means j?
		return (j);
	return (i);
}

int	main()
{
	char *str = "abcdef";
	char *str2 = "khl";
	printf("%zu\n", ft_strcspn(str, str2));
	return (0);
}
