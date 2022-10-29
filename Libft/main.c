/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:23:17 by mmakarov          #+#    #+#             */
/*   Updated: 2022/10/28 19:00:27 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main()
{
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

//	char s[5] = "Salut";
//	ft_memset(s, '.', 3);
//	printf("%s\n", s);

//	char s[6] = "Salut!";
//	ft_bzero(s, 5);
//	printf("%s\n", s);

//	char dst[60] = "Salut";
//	char src[30] = "cat";
//	ft_memcpy(dst, src, 3);
//	printf("%s\n", src);

//don't work:

	printf("%s\n", ft_strnstr("This is just a String", "just", 7));
//	printf("%s\n", strnstr("This is just a String", "just", 4));

	return (0);
}
