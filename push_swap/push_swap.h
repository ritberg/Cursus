/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:23:15 by mmakarov          #+#    #+#             */
/*   Updated: 2023/01/10 20:06:14 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //del !

# define MIN_TO_MAX 0
# define MAX_TO_MIN 1

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

//sim_to_libft.c
char			*ft_strcpy(char *dst, char *src); //not strlpy but strcpy
int				ft_isdigit(char *str); //not for char c, but char *str
long long int	ft_atoi(const char *str); //long long instead of int
t_list			*ft_lstnew_int(int content); // params: int instead of void *

// temp_libft.c 
size_t			ft_strlen(const char *s);
void			ft_lstadd_back(t_list **lst, t_list *new);
t_list			*ft_lstlast(t_list *lst);
int				ft_lstsize(t_list *lst);

//ft_strjoin.c
char			*ft_strjoin(char const *s1, char const *s2);

//ft_split.c
char			**ft_split(char const *s, char c);

//err_checker.c
int				err_input_checker(int argc, char **argv);
char			**input_as_str(char **argv);
int				n_of_n(char **a);

//already_sorted.c
int				already_sorted(t_list *pile_a);

//create_pile.c
t_list			*create_pile(int argc, char **argv);

//rules_r.c
t_list			*rra_rrb(t_list *pile, int size, char c);
t_list			*ra_rb(t_list *pile, int size, char c);

//rules_s_p.c
t_list			*sa_sb(t_list *pile, int size, char c);
int				pa(t_list **pile_a, t_list **pile_b);
int				pb(t_list **pile_a, t_list **pile_b);

// small_sort_max_10.c
void			sm_sort_max_10(t_list **pile_a, t_list **pile_b, int direction);
// small_sort.c
void			small_sort(t_list **pile_a, t_list **pile_b, int direction);

// small_sort_r.c
void			small_sort_r(t_list **pile_b, t_list **pile_a, int direction);
//very_small_sort_r.c
t_list			*very_small_sort_r(t_list *pile_b);

//very_small_sort.c
t_list			*very_small_sort(t_list *pile_a);

//sort_pile_k.c
void			sort_pile_k(t_list *pile_a, int argc, char **argv);
void			get_index(t_list *pile_k, t_list *pile_a);
void			swap(t_list *one, t_list *two);

//middle_sort.c
void			middle_sort(t_list **pile_a, t_list **pile_b);

//big_sort.c
void			big_sort(t_list **pile_a, t_list **pile_b);

//free in main
void			free_piles(t_list *pile_a);
void			free_char(char **new_argv);

//printlist.c     del !!!!!!!
void			printlist(t_list *head); // !!!!!!

#endif
