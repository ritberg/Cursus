/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:42:21 by mmakarov          #+#    #+#             */
/*   Updated: 2023/01/05 13:46:01 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**input_as_str(char **argv)
{
	char	**a;

	a = ft_split(argv[1], ' '); //if input is like "6 4 1 23 -4"
	if (a == NULL)
		return (NULL);
	return (a);
}

static int     n_of_n(char **a)
{
        int     i;
        int     j;

        j = 0;
        while (a[j] != NULL)
        {
                i = 0;
                while (a[i])
                        i++;
                j++;
        }
        return (j); //return how many numbers in **a (or **argv). Kind of argc
}

static int	err_checker(int argc, char **argv) //check all errors
{
	int	j;
	int	i;

	j = 1;
	while (j < argc)
	{
		if (!ft_isdigit(argv[j])) //autres char non autorises non plus
			return (0);
		if (ft_atoi(argv[j]) > 2147483647 || ft_atoi(argv[j]) < -2147483648)
			return (0);
		i = j + 1;
		while (i < argc)
		{
			if (ft_atoi(argv[j]) == ft_atoi(argv[i]))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	err_input_checker(int argc, char **argv) //function that put all together
{
	char	**a;
	int		i;

	i = 0;
	if (argv == NULL)
		return (0);
	if (argc == 2)
	{
		a = input_as_str(argv);
		i = n_of_n(a);
		return (err_checker(i, a));
	}
	return (err_checker(argc, argv));
}
