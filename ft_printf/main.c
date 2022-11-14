/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:50:48 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/14 19:30:05 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main()
{
	char	*s = "cspdiuxX%";

//	ft_printf(s, 42);
//	printf("\n Un nombre décimal (base 10): %d\n", 42);

//	ft_printf(s, 'a');
//	printf("\n Un seul caractère: %c\n", 'a');

//	ft_printf(s, 2, "abc", NULL);
//	printf("\n Chaîne de caractères: %s\n", "abc");

	void	*p = "abc";
	ft_printf(s, &p);
	printf("\n Pointeur de chaîne: %p\n", &p);
	return (0);
}
