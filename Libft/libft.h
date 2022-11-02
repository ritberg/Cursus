/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:36:26 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/02 19:39:25 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>


////// Part I ////

//int	ft_isalpha(int i);
//int	ft_isdigit(int c);
//int	ft_isalnum(int c);
//int	ft_isascii(int c);
//int	ft_isprint(int c);
//size_t	ft_strlen(const char *s);
//int	ft_atoi(const char *str);
//int	ft_toupper(int c);
//int	ft_tolower(int c);
//char	*ft_strchr(const char *s, int c);
//char	*ft_strrchr(const char *s, int c);
//void	*ft_memset(void *s, int c, size_t n);
//void	ft_bzero(void *s, size_t n);
//int	ft_strncmp(const char *s1, const char *s2, size_t n);
//void	*ft_memcpy(void *dst, const void *src, size_t n);
//char	*ft_strnstr(const char *haystack, const char *needle, size_t len);	
//void	*ft_memmove(void *dst, const void *src, size_t len);
//size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
//int	ft_strlen(const char *str);                                    //!! auxiliere
//size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
//void	*ft_memchr(const void *s, int c, size_t n);
//int	ft_memcmp(const void *s1, const void *s2, size_t n);

//char	*ft_strdup(const char *s1);
//void	*ft_calloc(size_t count, size_t size);


/////// Part II ////

//char	*ft_substr(char const *s, unsigned int start, size_t len);

//char	*ft_strjoin(char const *s1, char const *s2);            
//char	*ft_strcpy(char *dst, char *src);                //auxiliere
//char	*ft_strcat(char *dst, char *src);                //auxiliere

//char	*ft_strtrim(char const *s1, char const *set);
//int	ft_check(char c, const char *str);

char	**ft_split(char const *s, char c);
int	*ft_len_strs(char *str, char c, int n_words);
int	ft_n_words(char *str, char c);

//char	*ft_itoa(int n);
//void	ft_mod(int n);

int	main();

#endif
