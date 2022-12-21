/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:23:15 by mmakarov          #+#    #+#             */
/*   Updated: 2022/12/21 14:24:21 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void *content;
	struct s_list *next;
}	t_list;

//sim_to_libft
char	*ft_strcpy(char *dst, char *src);

// temp_libft -- del
size_t	ft_strlen(const char *s);
int	ft_isalpha(int c);
int	ft_atoi(const char *str);

//err_checker
void	err_checker(int argc, char **argv);

//sorting.c
char	sorting(int *number, int total_num);

#endif
