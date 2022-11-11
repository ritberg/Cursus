/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:31:12 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/10 11:11:12 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Ajouter l’élément ’new’ au début de la liste

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst; //add lst to new element, i.e. lst goes after new
	*lst = new; // the pointer lst now points to the new element. new becomes first element
}
