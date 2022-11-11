/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:57:39 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/10 09:45:33 by mmakarov         ###   ########.fr       */
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
	int	index;
	int	len;
	int	*len_strs;

	len_strs = malloc(sizeof(int) * n_words); //len of each word
	if (len_strs == 0)
		return (0);
	index = 0;
	while (*str)
	{
		if (*str != c)
		{
			len = 0; //initialization of the len of a new word
			while (*str && *str != c)
			{
				str++;
				len++;
			}                         // when this while loop ends, the word ends
			len_strs[index++] = len + 1; // put len of the word inside malloc + '\0'
			                             // index is a new word
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
		free(dst[k++]); //free each row counting from a certain row
	free(dst);        // free all the table
	return (NULL);
}

static char	**ft_fill_big_table(char *src, char c, char **dst, int *lens)
{
	int	j;
	int	count;

	count = 0; //count is 0 again. to avoid to declare a new variable
	while (*src) //*srcr and src++ per isparmio dello spazio
	{
		if (*src != c)
		{
			dst[count] = malloc(sizeof(char) * lens[count]); // memory for len 
			if (dst[count] == NULL)                  //of each word (row, i.e. horiz. ->)
				return (ft_free_split(dst, count));
			j = 0;                              
			while (*src && *src != c)  //this while loop is needed to 
				dst[count][j++] = *src++; // fill the rows of dst
		                                    	//   src++ is  go to the next letter
			                         	// j++ is  go to the next column (vertic.)
			dst[count++][j] = '\0';  //count is index for words (in dst) 
			                        //and src++ is index for characters (in src)
		}
		else
			src++;
	}
	dst[count] = NULL; //pointeur sur 0 qui indique que le tableau est fini
	                   //equivalent of '\0' for *str
	free(lens);
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	*src;
	char	**dst;
	int	*lens;
	int	count;

	src = (char *)s;
	count = ft_n_words(src, c);  // how many words
	lens = ft_len_strs(src, c, count);  //how long are the words. this is an array.
                                        //	ex, "This is" {4, 2}
	dst = malloc(sizeof(char *) * count); //dst deve avere una riga per ogni parola
	if (dst == NULL)
		return (NULL);
	return (ft_fill_big_table(src, c, dst, lens));
}
