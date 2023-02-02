#include "stdlib.h"
#include "stdio.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*str_ret;
	int	i;

	i = 0;
	str_ret = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (str_ret == NULL)
		return (NULL);
	while (src[i])
	{
		str_ret[i] = src[i];
	   i++;	
	}
	str_ret[i] = '\0';
	return (str_ret);
}

int	main()
{
	char *src = "Salut";
	printf("%s\n", ft_strdup(src));
	return (0);
}
