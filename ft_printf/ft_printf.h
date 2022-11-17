/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:50:29 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/17 17:26:22 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>   // to remove before submission !!

int		ft_printf(const char *s, ...);
int		ft_putchar(char c);
void	ft_putstr(char *str);

int		ft_dec_to_hexadec_min(int i);
int		ft_dec_to_hexadec_maj(int i);
int		ft_dec_to_hexadec_p(long int i);

int		ft_n(const char *s, int ind, va_list args);
int		ft_c(const char *s, int ind, va_list args);
int		ft_str(const char *s, int ind, va_list args);
int		ft_hex_min(const char *s, int ind, va_list args);
int		ft_hex_maj(const char *s, int ind, va_list args);
int		ft_pointer(const char *s, int ind, va_list args);

int	main();

#endif
