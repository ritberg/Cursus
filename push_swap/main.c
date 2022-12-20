/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:18:03 by mmakarov          #+#    #+#             */
/*   Updated: 2022/12/19 15:23:02 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

char	*ft_strcpy(char *dst, char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	main(int argc, char **argv)
{
	int	j;
	char	**read_input;

	read_input = malloc(sizeof(char) * (argc - 1));
	j = 1;
	while (j < argc)
	{
		read_input[j - 1] = malloc(sizeof(**char) * ft_strlen(argv[j]));
		strcpy(read_input[j - 1], argv[j])
		j++;

	}
	return (0);
}
