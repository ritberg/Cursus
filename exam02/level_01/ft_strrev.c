#include "stdio.h"
#include "stdlib.h"

int	ft_strlen(char *str)
{
	int	len;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strrev(char *str)
{
	char	*str_ret;
	int	len;
	int	i;
	
	i = 0;
	len = ft_strlen(str);
	str_ret = malloc(sizeof(char) * len + 1);
	if (str_ret == NULL)
		return (NULL);
	len -= 1;
	while (len >= 0)
	{
		str_ret[i] = str[len];
		i++;
		len--;
	}
	str_ret[i] = '\0';
	return (str_ret);
}

int	main()
{
	char *str = "Salut";
	printf("%s\n", ft_strrev(str));
	return (0);
}
