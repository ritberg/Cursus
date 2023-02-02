#include "stdio.h"
#include "string.h"

// return : all the letters of s1 after a matching character in both s1 and s2
// ex: with this main answer is "3j9"

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	j;

	j = 0;
	while (s2[j])
	{
		while (*s1)
		{
			if (*s1 == s2[j])
				return ((char *)s1);
			s1++;
		}
		j++;
	}
	return (NULL);
}

/* version github
char *ft_strpbrk(const char *s1, const char *s2)
{
	int i = 0;
	
	if (!s1 || !s2)
	{
		return (0);
	}
	while(*s1)
	{
		i = 0;
	   	while(s2[i])
		{
			if(*s1 == s2[i])
				return (char *) s1;
			i++;
		}
		s1++;	
	}
	return (0);
}
*/

int	main()
{
	char *s1 = "abcd3j9";
	char *s2 = "34";
	printf("%s\n", ft_strpbrk(s1, s2));
	printf("%s\n", strpbrk(s1, s2));
	return (0);
}
