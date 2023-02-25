#include "fractol.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	char	*src;
	int		len;
	int		i;

	src = (char *)s1;
	len = 0;
	while (src[len])
		len++;
	dst = malloc(sizeof(*src) * (len + 1));
	if (dst == NULL)
		return (NULL);
	if (src == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
