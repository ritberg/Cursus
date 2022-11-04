/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:23:17 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/04 18:02:17 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main()
{

/////// Part I //////


//	printf("%d\n", ft_isalpha(111));
//	printf("%d\n", ft_isdigit(55));
//	printf("%d\n", ft_isalnum(178));
//	printf("%d\n", ft_isascii(0177));
//	printf("%d\n", ft_isprint('~'));
//	printf("%zu\n", ft_strlen("Rita"));
//	printf("%d\n", ft_atoi("   ---++-123hfjf"));
//	printf("%d\n", ft_toupper(122));
//	printf("%d\n", ft_tolower(126));
//	printf("%s\n", ft_strchr("This is just a String", 'S'));
//	printf("%s\n", ft_strrchr("This-is-just-a-String", '-'));
//	printf("%d\n", ft_strncmp("This is", "This is", 100));

//	printf("%s\n", ft_strnstr("nannb", "nanb", 7));
//	printf("%s\n", ft_strnstr("wawawb", "wawb", 7));
//	printf("%s\n", ft_strnstr("Thii is a string", "is", 10));

/*
char s[5] = "Salut";
ft_memset(s, '.', 3);
printf("%s\n", s);
*/

/*
char s[6] = "Salut!";
ft_bzero(s, 5);
printf("%s\n", s);
*/

/*
char src[60] = "012345678";
char *dst = src + 4;
ft_memcpy(dst, src, 6);
printf("%s\n", dst);
*/

/*
char src[30] = "012345678";
char *dst = src + 4;
ft_memmove(dst, src, 6);
printf("%s\n", dst);
*/

//	char src[30] = "is a string";
//	char dst[30] = "This ";
//	ft_strlcpy(dst, src, 30);
//	printf("%s\n", dst);

/*
char src[30] = "is a string";
char dst[30] = "This ";
ft_strlcat(dst, src, 30);
printf("%s\n", dst);
*/

//	printf("%s\n", ft_memchr("This.is.just.a.String", '.', 90));
//	printf("%s\n", memchr("This.is.just.a.String", '.', 90));

//	printf("%d\n", ft_memcmp("This is a", "This is", 100));
//	printf("%d\n", memcmp("This is a", "This is", 100));

//	char	*s1 = "This is a sentence";
//	char	*s2;
//	printf("%s\n", ft_strdup(s1));

//printf("%p\n", ft_calloc(5, 4));


////// Part II //////

//	char const	*s = "This is a sentence";
//	unsigned int	start = 5;
//	size_t	len = 4;
//	printf("%s\n", ft_substr(s, start, len));

/*
char	*s1 = "This is a stupid ";
char	*s2 = "sentence";
printf("%s\n", ft_strjoin(s1, s2));
*/

/*
char	*s1 = "     This is a stupid sentence. ....";
char	*set = " .";
printf("%s\n", ft_strtrim(s1, set));
*/

/*
char	**tab;
char	*s = "   This  is a cat ";
char	c = ' ';
int	i;

i = 0;
tab = ft_split(s, c);
while (i < 4) //change while testing!!!!
{
	printf("%s\n", tab[i]);
	i++;
}
*/

//printf("%s\n", ft_itoa(67643));

/*
char	src[10] = "Salut";
char	*dst =  ft_strmapi(src, ft_function);
printf("source: %s\n", src);
printf("dest: %s\n", dst);
*/

/*
char	*s = "Salut";
int	fd = 1;
ft_putendl_fd(s, fd);
*/

/*
int	n = -42;
int	fd = 1;
ft_putnbr_fd(n, fd);
*/

	return (0);
}
