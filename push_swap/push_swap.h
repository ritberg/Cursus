/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:23:15 by mmakarov          #+#    #+#             */
/*   Updated: 2022/12/21 17:55:10 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //del !

typedef struct s_list
{
	int *content;
	struct s_list *next;
}	t_list;

//sim_to_libft
char	*ft_strcpy(char *dst, char *src);
int	ft_isalpha(char *str);
long long int	ft_atoi(const char *str);

// temp_libft -- del
size_t	ft_strlen(const char *s);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);

//err_checker
void	err_checker(int argc, char **argv);

// new_index

#endif
