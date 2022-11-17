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

# include "libft.h"

int		ft_printf(const char *s, ...);
//void		ft_putchar_fd(char c, int fd);
//void		ft_putnbr_fd(int nb, int fd);
//void	ft_putstr_fd(char *str, int fd);

int		ft_dec_to_hexadec_min(int i);
int		ft_dec_to_hexadec_maj(int i);
int		ft_dec_to_hexadec_p(long int i);

int		ft_n(va_list args);
int		ft_c(va_list args);
int		ft_str(va_list args);
int		ft_hex_min(va_list args);
int		ft_hex_maj(va_list args);
int		ft_pointer(va_list args);

//int	main();

#endif
