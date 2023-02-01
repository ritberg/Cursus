#include "stdio.h"

// return : how many letters are different before a character that matches (in this main it's f)
// if there is the same letter in s as in reject, return its index in s
// ex: answer with main below is 5. it's the index of the letter "f" in s

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
