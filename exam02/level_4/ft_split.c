#include "stdlib.h"
#include "stdio.h"


int	ft_is_delimiter(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

int	ft_words_len(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (!ft_is_delimiter(str[i]))
		{
			len++;
			i++;
		}
		else
			i++;
	}
	return (len);
}

char	*ft_get_word(char *str)
{
	int			i;
	char		*word;

	i = 0;
	while (str[i] && !ft_is_delimiter(str[i]))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (str[i] && !ft_is_delimiter(str[i]))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	int		i;
	char	**split;

	i = 0;
	split = (char **)malloc(sizeof(char *) * ft_words_len(str) + 1);
	if (split == NULL)
		return (NULL);
	while (*str)
	{
		while (*str && ft_is_delimiter(*str))
			str++;
		if (*str && !ft_is_delimiter(*str))
		{
			split[i] = ft_get_word(str);
			i++;
		}
		while (*str && !ft_is_delimiter(*str))
			str++;
	}
	split[i] = NULL;
	return (split);
}

/*
int	main()
{
	char	*str = "Salut mes amis bababa !";
	char	**tab = ft_split(str);
	int	i = 0;
	while (i <= 4)
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}
*/
