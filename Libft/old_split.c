/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:57:39 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/09 17:02:08 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_n_words(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c) // count how many words there are: 
				i++;                    //from one delimiter to an other
		}
		else
			i++;
	}
	return (count);
}

static int	*ft_len_strs(char *str, char c, int n_words)
{
	int	i;
	int	count;
	int	len;
	int	*len_strs;

	len_strs = malloc(sizeof(int) * n_words); //len of each word
	i = 0;
	len = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			while (str[i] && str[i] != c)
			{
				i++;
				len++;
			}
			len_strs[count] = len + 1;
			len = 0;
			count++;
		}
		else
			i++;
	}
	return (len_strs);
}

char	**ft_free_split(char **dst, size_t i)
{
	size_t	k;

	k = 0;
	while (k < i)
		free(dst[k++]); //free each row counting from a certain row
	free(dst);        // free all the table
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	*src;
	char	**dst;
	int	i;
	int	j;
	int	count;
	int	*lens;

	src = (char *)s;
	count = ft_n_words(src, c);  // how many words
	lens = ft_len_strs(src, c, count);  //how long are the words. this is an array.
                                        //	ex, "This is" {4, 2}
	dst = malloc(sizeof(char *) * count); //dst deve avere una riga per ogni parola
	if (dst == NULL)
		return (NULL);
	i = 0;
	j = 0;
	count = 0; //count is 0 again. to avoid to declare a new variable
	while (src[i])
	{
		if (src[i] != c)
		{
			dst[count] = malloc(sizeof(char) * lens[count]); // memory for len 
			if (dst[count] == NULL)                  //of each word (row, i.e. horiz.
				return (ft_free_split(dst, count));
			j = 0;                              
			while (src[i] && src[i] != c)  //this while loop is needed to 
				                          //fill the rows..
			{
				dst[count][j] = src[i]; // ..for j columns
				i++;        // go to the next letter
				j++;        // go to the next column (vertic.)
			}
			dst[count][j] = '\0';
			count++; //count is index for words (in dst) 
			        //and i is index for characters (in src)
		}
		else
			i++;
	}
	dst[count] = NULL; //pointeur sur 0 qui indique que le tableau est fini
	free(lens);
	return (dst);
}
