/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:32:57 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/10 17:42:14 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 Supprime et libère la mémoire de l’élément passé en
paramètre, et de tous les éléments qui suivent, à
l’aide de ’del’ et de free(3)
Enfin, le pointeur initial doit être mis à NULL.
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	
	if (lst && *lst && del)
	{
		while (*lst)
		{
			del((*lst)->content);
			temp = *lst;
			*lst = temp->next;
			free(temp);
		}
	}
	*lst = NULL;
}
/*
{
	t_list	*temp;

	if (lst && *lst && del)
	{
		while (*lst)
		{
			temp = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = temp;
		}
	}
//	lst = NULL;
//	free(lst);
}
*/
