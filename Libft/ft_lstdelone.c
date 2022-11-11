/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:24:29 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/10 13:05:42 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 Libère la mémoire de l’élément passé en argument en
utilisant la fonction ’del’ puis avec free(3). La
mémoire de ’next’ ne doit pas être free.
 */

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del) //on doit s'assurer que la fonction del existe
	{
		del(lst->content);
		free(lst);
	}
}
// this function is for 1 pointer (*lst)
