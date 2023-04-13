/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:41:26 by mmakarov          #+#    #+#             */
/*   Updated: 2023/04/13 15:09:57 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
	chercher PATH, recuperer ce qui suit apres PATH= (cf. env)
	split par :
	ajouter / a la fin de chaque ligne
*/

int	parsing_path(t_ppx *ppx, char **envp)
{

	// raccourcir !!!!!

	char *temp_path;

	ppx->j = 0;
	ppx->path_envp = NULL; //protection
	while (envp[ppx->j])
	{
		if (ft_strncmp("PATH=", envp[ppx->j], 5) == 0)
		{
			ppx->path_envp = envp[ppx->j] + 4; //+4 to remove PATH=
			break;
		}
		ppx->j++;
	}
	if (!ppx->path_envp)
		return (my_perror("PATH unset", ppx));
	ppx->mypaths = ft_split(ppx->path_envp, ':');
	//free(ppx->path_envp); //
	if (!ppx->mypaths)
		return (my_perror("Split error", ppx));
	ppx->j = 0;
	while (ppx->mypaths[ppx->j])
	{
		temp_path = ft_strjoin(ppx->mypaths[ppx->j], "/");
		if (!ppx->mypaths)
			return (my_perror("Strjoin error", ppx));
		free(ppx->mypaths[ppx->j]);
		ppx->mypaths[ppx->j] = temp_path;
		ppx->j++;
	}
	return (1);
}

/*
   split commandes donnees en params par ' '. ex, ls -la
*/
int	parsing_args(t_ppx *ppx, char **argv)
{

	//ppx->mycmdargs2 = ft_split(argv[2], ' '); //  what if "grep 'a cat'"?
	ppx->mycmdargs2 = ft_splitpath(argv[2], ' ');
	if (!ppx->mycmdargs2)
		return (my_perror("Split error", ppx));
	//ppx->mycmdargs3 = ft_split(argv[3], ' ');
	ppx->mycmdargs3 = ft_splitpath(argv[3], ' ');
	if (!ppx->mycmdargs3)
		return (my_perror("Split error", ppx));
	return (1);
}

/*
   mycmdargs = commandes passees en params. il faut les chercher dans /bin
   des qu'on a trouve, break
   cmd1 = path of the first command cat, ex /bin/cat
   envoyer une erreur (-1) si la commande n'est pas valide
*/

int	find_cmd1(t_ppx *ppx)
{
	ppx->j = 0;
	while (ppx->mypaths[ppx->j])
	{
		ppx->cmd1 = ft_strjoin(ppx->mypaths[ppx->j], ppx->mycmdargs2[0]);
		if (!ppx->cmd1)
			return (my_perror("Strjoin error", ppx));
		ppx->ok = access(ppx->cmd1, F_OK & X_OK);
		if (ppx->ok == 0)
			break;
		free(ppx->cmd1);
		ppx->j++;
	}
	if (ppx->ok == -1)
		return (my_perror("Error", ppx));
	return (1);
}

int	find_cmd2(t_ppx *ppx)
{
	ppx->j = 0;
	while (ppx->mypaths[ppx->j])
	{
		ppx->cmd2 = ft_strjoin(ppx->mypaths[ppx->j], ppx->mycmdargs3[0]);
		if (!ppx->cmd2)
			return (my_perror("Strjoin error", ppx));
		ppx->ok = access(ppx->cmd2, F_OK & X_OK);
		if (ppx->ok == 0)
			break;
		free(ppx->cmd2);
		ppx->j++;
	}
	free_tab(ppx->mypaths); //free mypaths
	if (ppx->ok == -1)
		return (my_perror("Error", ppx));
//	printf("print");///
	return (1);
}
