/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:48:30 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/10 17:55:32 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 Itère sur la liste ’lst’ et applique la fonction
’f ’au contenu de chaque élément. Crée une nouvelle
liste résultant des applications successives de
’f’. La fonction ’del’ est là pour détruire le
contenu d’un élément si nécessaire.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*first_elem;

	first_elem = NULL; //initialisation, pointeur sur NULL
	if (!lst || !del)
		return (NULL);
	while (lst)
	{
		new_list = ft_lstnew(f(lst->content)); //malloc is inside lstnew
		                            //mettre dans new_list les elements 
		                                     //de la lst modifie par la fonction f
		if (new_list == NULL)
		{                                  //c'est similaire a ft_split
			ft_lstclear(&first_elem, del); //faut garder en memoire le premier element
			return (NULL);                 //free is inside ft_lstlear
		}
		ft_lstadd_back(&first_elem, new_list); //add le nouvel element qu'on a cree a la fin
		lst = lst->next; // ca remplace i++
	}
	return (first_elem);
}
