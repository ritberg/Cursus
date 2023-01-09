/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:23:17 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/10 14:38:43 by mmakarov         ###   ########.fr       */
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
//	printf("%d\n", ft_toupper(122));
//	printf("%d\n", ft_tolower(126));
//	printf("%s\n", ft_strchr("This is just a String", 'S'));
//	printf("%s\n", ft_strrchr("This-is-just-a-String", '-'));
//	printf("%d\n", ft_strncmp("This is", "This is", 100));


//	printf("%d\n", ft_atoi("   ---++-123hfjf"));

/*
	printf("%s\n", ft_strnstr("nannb", "nanb", 7));
	printf("%s\n", ft_strnstr("wawawb", "wawb", 7));
	printf("%s\n", ft_strnstr("Thii is a string", "is", 10));
*/

/*
char s[5] = "Salut";
ft_memset(s, '.', 3);
printf("%s\n", s);
*/

/*
char s[20] = "Salut!";
ft_bzero(s, 3);
printf("%s\n", s);
*/

/*
char src[60] = "zyxwvutsrqponmlkjihgfedcba";
char dst[60] = "jjjjjjjjjjjjjjjjjjjjjjjjjjjjjj";
ft_memcpy(dst, src, 14);
printf("%s\n", dst);
*/

/*
char *src = NULL;
char *dst = NULL;
ft_memmove(dst, src, 6);
printf("%s\n", dst);
*/

/*
char src[30] = "is a string";
char dst[30] = "This ";
ft_strlcpy(dst, src, 30);
printf("%s\n", dst);
*/
/*
char src[30] = "is a string";
char dst[30] = "This ";
ft_strlcat(dst, src, 30);
printf("%s\n", dst);
*/
/*
	printf("%s\n", ft_memchr("This.is.just.a.String", '.', 90));
	printf("%s\n", memchr("This.is.just.a.String", '.', 90));
*/
/*
	printf("%d\n", ft_memcmp("This is a", "This is", 100));
	printf("%d\n", memcmp("This is a", "This is", 100));
*/
/*
	char	*s1 = "This is a sentence";
	char	*s2;
	printf("%s\n", ft_strdup(s1));
*/

//printf("%p\n", ft_calloc(5, 4));


////// Part II //////

/*
	char const	*s = "This is a sentence";
	unsigned int	start = 5;
	size_t	len = 4;
	printf("%s\n", ft_substr(s, start, len));
*/
/*
char	*s1 = "This is a stupid ";
char	*s2 = "sentence";
printf("%s\n", ft_strjoin(s1, s2));
*/

/*
char	*s1 = "";
char	*set = "";
printf("%s\n", ft_strtrim(s1, set));
*/

///// FT_SPLIT //////


/*
	char	**tab;
	char	*s = "      split       this for   me  !";
	char	c = ' ';
	int	i;

	i = 0;
	tab = ft_split(s, c);
	while (tab[i] != NULL)
	{
		printf("%s\n", tab[i]);
		i++;
	}

*/

/*
void	ft_print_result(char const *s)
{
	int		len;
	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
int	main()
*/

/*
char	**tabstr;
int		i;

if (!(tabstr = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ')))
			ft_print_result("NULL");
		else
		{
			while (tabstr[i] != NULL)
			{
				ft_print_result(tabstr[i]);
				write(1, "\n", 1);
				i++;
			}
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



////// BONUS ///////



	return (0);
}
