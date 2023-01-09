/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:42:21 by mmakarov          #+#    #+#             */
/*   Updated: 2023/01/09 16:32:59 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**input_as_str(int argc, char **argv)
{
	char	**a;
	
	//ft_strjoin(argv[0], argv[1]) ?	
	a = ft_split(argv[1], ' '); //if input is like "6 4 1 23 -4"
	if (a == NULL)
		return (NULL);
	return (a); //it dsnt return ./push_swap ! it should
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

static int	err_checker_argc2(int ac, char **av) //check all errors
{
	int	j;
	int	i;

	j = 0; //from argv[0]
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

static int	err_checker(int ac, char **av) //check all errors
{
	int	j;
	int	i;

	j = 1; //from argv[1]
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

	i = 0;
	if (argv == NULL)
		return (0);
	if (argc == 2)
	{
		a = input_as_str(argc, argv);
		i = n_of_n(a);
		return (err_checker_argc2(i, a)); //change ! common check
	}
	return (err_checker(argc, argv));
}
