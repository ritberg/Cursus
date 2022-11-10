/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:48:30 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/10 16:31:29 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*first_elem;

	if (!lst || !del)
		return (NULL);
	while (lst)
	{
		new_list = malloc(sizeof(t_list));
		if (new_list == NULL)
		{                                  //c'est similaire a ft_split
			ft_lstclear(&first_elem, del); //faut garder en memoire le premier element
			return (NULL);                 //free is inside ft_lstlear
		}
		new_list->content = f(lst->content);  //mettre dans new_list les elements 
		                                     //de la lst modifie par la fonction f
		ft_lstadd_back(&first_elem, new_list); //add le nouvel element qu'on a cree a la fin
		lst = lst->next; // ca remplace i++
	}
	return (new_list);
}
