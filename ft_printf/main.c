/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:50:48 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/21 14:56:41 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main()
{
//	ft_printf("%d\n", 2147483647);
//	printf("Un nombre décimal (base 10): %d\n", 2147483647);

//	ft_printf("%u\n", -1); //unsigned is always pos !
//	printf("Un nombre u: %u\n", -1);
	
//	ft_printf("%i\n", 42);
//	printf("Un nombre i: %i\n", 42);

//	ft_printf("%c\n", 'a');
//	printf("Un seul caractère: %c\n", 'a');

//	ft_printf("%s\n", "abc"); // NULL as last arg??
//	printf("Chaîne de caractères: %s\n", "abc");

	int x = 1 + 2;
	void	*p = &x;
	ft_printf("%p\n", p);
	printf("Pointeur: %p\n", p);
	

/*	Afficher les valeurs de retour pour x:
	long l = 25;

	int r1 = ft_printf("%x", l);
	int r2 = printf("%lx", l);
	printf("\n R1 = %i, R2 = %i\n", r1, r2);
*/
/*
	ft_printf("%x\n", 103087);
	printf("Un nombre en hexadécimal (base 16) min: %x\n", 103087);

	ft_printf("%X\n", 103087);
	printf("Un nombre en hexadécimal (base 16) maj: %X\n", 103087);
	

	ft_printf("%%%%%%%\n");
	printf("\n%%%%%%%\n");
*/
	ft_printf("salut\n");
	printf("salut\n");


	return (0);
}
