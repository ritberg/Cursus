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
//	ft_printf("%d\n", 42);
//	printf("Un nombre décimal (base 10): %d\n", 42);

//	ft_printf("%c\n", 'a');
//	printf("Un seul caractère: %c\n", 'a');

//	ft_printf("%s\n", "abc"); // NULL as last arg??
//	printf("Chaîne de caractères: %s\n", "abc");

	void	*p = "abc";
	ft_printf("%p\n", &p);
	printf("Pointeur de chaîne: %p\n", &p);

	return (0);
}
