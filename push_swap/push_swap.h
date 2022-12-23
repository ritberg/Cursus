/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:23:15 by mmakarov          #+#    #+#             */
/*   Updated: 2022/12/23 12:16:21 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //del !

typedef struct s_list
{
	int content;
	struct s_list *next;
}	t_list;

//sim_to_libft.c
char	*ft_strcpy(char *dst, char *src); //not strlpy but strcpy
int	ft_isdigit(char *str); //not for char c, but char *str
long long int	ft_atoi(const char *str); //long long instead of int
t_list	*ft_lstnew_int(int content); // params: int instead of void *

// temp_libft.c -- del
size_t	ft_strlen(const char *s);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);

//err_checker.c
int	err_checker(int argc, char **argv);

//create_pile_a.c
t_list	*create_pile_a(int argc, char **argv);

//printlist.c     del !!!!!!!
void	printlist(t_list *head); // !!!!!!

#endif
