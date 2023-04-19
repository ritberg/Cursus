/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:23:03 by mmakarov          #+#    #+#             */
/*   Updated: 2023/04/12 18:53:05 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		free(tab[i++]);
	free(tab);
}

int	my_perror(const char *str, t_ppx *ppx)
{
	ppx->j = 0;
	while (ppx->mypaths && ppx->mypaths[ppx->j])
		free(ppx->mypaths[ppx->j++]);
	free(ppx->mypaths);
	ppx->j = 0;
	while (ppx->mycmdargs2 && ppx->mycmdargs2[ppx->j])
		free(ppx->mycmdargs2[ppx->j++]);
	free(ppx->mycmdargs2);
	ppx->j = 0;
	while (ppx->mycmdargs3 && ppx->mycmdargs3[ppx->j])
		free(ppx->mycmdargs3[ppx->j++]);
	free(ppx->mycmdargs3);
	free(ppx);
	perror(str);
	return (EXIT_FAILURE);
}

int	error_checker(int argc, t_ppx *ppx)
{
	if (argc != 5)
		return (my_perror("Args problem", ppx));
	return (EXIT_SUCCESS);
}
