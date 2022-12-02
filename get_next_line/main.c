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
	int	fd1;
//	int	fd2;

	fd1 = open("test2.txt", O_RDONLY);
	printf("%s", get_next_line(fd1));
//	fd2 = open("test.txt", O_RDONLY);
//	printf("%s", get_next_line(fd2));
//	printf("%s\n", get_next_line(fd));
	return (0);
}
