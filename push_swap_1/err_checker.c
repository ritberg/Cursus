/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:42:21 by mmakarov          #+#    #+#             */
/*   Updated: 2023/01/05 16:28:21 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**argv_without_0(int argc, char **argv)
{
	int		i;
	char	**new_argv;

	new_argv = malloc(sizeof(char *) * (argc - 1 + 1));
	if (!new_argv)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		new_argv[i - 1] = ft_strdup(argv[i]);
		i++;
	}
	new_argv[i - 1] = NULL;
	return (new_argv);
}

char	**input_as_str(char **argv)
{
	char	**a;

	a = ft_split(argv[1], ' '); //if input is like "6 4 1 23 -4"
	if (a == NULL)
		return (NULL);
	return (a);
}

int	n_of_n(char **a)
{
        int	i;
        int	j;

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

static int	err_checker(int ac, char **av) //check all errors
{
	int	j;
	int	i;

	j = 1;
	while (j < ac)
	{
		if (!ft_isdigit(av[j])) //autres char non autorises non plus
			return (0);
		if (ft_atoi(av[j]) > 2147483647 || ft_atoi(av[j]) < -2147483648)
			return (0);
		i = j + 1;
		while (i < ac)
		{
			if (ft_atoi(av[j]) == ft_atoi(av[i]))
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

	if (argv == NULL)
		return (0);
	if (argc == 2)
	{
		a = input_as_str(argv);
		i = n_of_n(a);
		return (err_checker(i, a));
	}
	a = argv_without_0(argc, argv);
	return (err_checker(argc, a));
}
