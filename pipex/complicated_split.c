
#include "pipex.h"

static int	ft_n_words(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str != c)
		{
			if (*str == 39)
			{
				count++;
				break;
			}
			else
			{
				count++;
				while (*str && *str != c)
					str++;
			}
		}
		else
			str++;
	}
	return (count);
}

static int	*ft_len_strs(char *str, char c, int count)
{
	int	index;
	int	len;
	int	*len_strs;

	len_strs = malloc(sizeof(int) * count);
	if (len_strs == 0)
		return (0);
	index = 0;
	while (*str)
	{
		if (*str != c)
		{
			len = 0;
			if (*str == 39)
			{
				str++;
				while (*str != 39)
				{
					str++;
					len++;
				}
				len_strs[index++] = len + 1;
				break;
			}
			else
			{
				while (*str && *str != c)
				{
					str++;
					len++;
				}
				len_strs[index++] = len + 1;
			}
		}
		else
			str++;
	}
	return (len_strs);
}

static char	**ft_free_split(char **dst, size_t i)
{
	size_t	k;

	k = 0;
	while (k < i)
		free(dst[k++]);
	free(dst);
	return (NULL);
}

static char	**ft_fill_big_table(char *src, char c, char **dst, int *lens)
{
	int	j;
	int	count;

	count = 0;
	while (*src)
	{
		if (*src != c)
		{
			dst[count] = malloc(sizeof(char) * lens[count]);
			if (dst[count] == NULL)
				return (ft_free_split(dst, count));
			if (*src == 39)
			{
				src++;
				j = 0;
				while (*src != 39)
					dst[count][j++] = *src++;
				dst[count++][j] = '\0';
				break;
			}
			else
			{
				j = 0;
				while (*src && *src != c)
					dst[count][j++] = *src++;
				dst[count++][j] = '\0';
			}
		}
		else
			src++;
	}
	dst[count] = NULL;
	free(lens);
	return (dst);
}

char	**ft_splitpath(char *s, char c)
{
	char	**dst;
	int		*lens;
	int		count;

	count = ft_n_words(s, c);
	lens = ft_len_strs(s, c, count);
/*
	int	a = 0;
	while (lens[a])
		printf("%d\n", lens[a++]);
*/
	dst = malloc(sizeof(char *) * count);
	if (dst == NULL)
		return (NULL);
	return (ft_fill_big_table(s, c, dst, lens));
}
