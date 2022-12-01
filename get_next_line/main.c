/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:18:52 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/28 14:44:25 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h> //del
#include <stdio.h> //del

int	main()
{
	int	fd;

	fd = open("test2.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
//	printf("TEST\n");
	printf("%s", get_next_line(fd));
//	printf("RE\n");
	printf("%s\n", get_next_line(fd));
	return (0);
}
