#include "stdio.h"

// take a letter from reject. If I find the same letter in s, return its index

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
/*
int	main()
{
	char *str = "abcdef";
	char *str2 = "vfo";
	printf("%zu\n", ft_strcspn(str, str2));
	return (0);
}
*/
