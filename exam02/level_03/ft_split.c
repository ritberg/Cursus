#include "stdlib.h"
#include "stdio.h"


/*

int	ft_is_delimiter(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

int	ft_words_len(char *str)
{
	int	idx;
	int	length;

	idx = 0;
	length = 0;
	while (str[idx] != '\0')
	{
		if (!ft_is_delimiter(str[idx]))
		{
			length++;
			idx++;
		}
		else
			idx++;
	}
	printf("lenght %d\n", length);
	return (length);
}

char	*ft_get_word(char *str)
{
	int			idx;
	char		*word;

	idx = 0;
	while (str[idx] != '\0' && !ft_is_delimiter(str[idx]))
		idx++;
	word = (char *)malloc(sizeof(char) * (idx + 1));
	if (!word)
		return (NULL);
	idx = 0;
	while (str[idx] != '\0' && !ft_is_delimiter(str[idx]))
	{
		word[idx] = str[idx];
		idx++;
	}
	word[idx] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	int		idx;
	char	**split;

	idx = 0;
	split = (char **)malloc(sizeof(char *) * ft_words_len(str) + 1);
	if (!split)
		return (NULL);
	while (*str)
	{
		while (*str && ft_is_delimiter(*str))
			str++;
		if (*str && !ft_is_delimiter(*str))
		{
			split[idx] = ft_get_word(str);
			idx++;
		}
		while (*str && !ft_is_delimiter(*str))
			str++;
	}
	split[idx] = NULL;
	return (split);
}
*/







int	ft_check(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int	len_without_delim(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!ft_check(str[i]))
			count++;
		i++;
	}
	return (count);
}

char	*ft_str(char *str)
{
	int	i;
	char	*tab;

	i = 0;
	while (str[i] && !ft_check(str[i]))
		i++;
	tab = malloc(sizeof(char) * (i + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (str[i] && !ft_check(str[i]))
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
	//printf("word %s\n", tab);
	return (tab);
}

char    **ft_split(char *str)
{
	int	i;
	int	j;
	int	len;
	char	**tab;

	i = 0;
	j = 0;
	len = len_without_delim(str);
	tab = malloc(sizeof(char) * len + 1);
	if (tab == NULL)
		return (NULL);
	while (str[i])
	{
		while (str[i] && ft_check(str[i]))
			i++;
		if (str[i] && !ft_check(str[i]))
		{
			tab[j] = ft_str(str + i); // position i !!
			j++;                    // I can also change str[i] for *str and str++ everywehere
		}
		while (str[i] && !ft_check(str[i]))
			i++;
	}
	tab[j] = NULL;
	return (tab);
}


int	main()
{
	char	*str = "Welcome to hell";
	int	j = 0;
	char	**tab = ft_split(str);

	while (tab[j] != NULL)
	{
		printf("%s\n", tab[j]);
		j++;
	}
	return (0);
}
