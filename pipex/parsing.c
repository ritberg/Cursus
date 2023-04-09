/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:41:26 by mmakarov          #+#    #+#             */
/*   Updated: 2023/04/09 18:43:05 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parsing(t_ppx *ppx, char **argv, char **envp)
{
	// chercher PATH et recuperer ce qui suit apres PATH=
	int	i;
	int	j;

	j = 0;
	ppx->path_envp = NULL; //protection
	while (envp[j])
	{
		if (ft_strncmp("PATH=", envp[j], 5) == 0)
		{
			ppx->path_envp = envp[j];
			break;
		}
		j++;
	}
	if (!ppx->path_envp)
		return (my_perror("PATH unset"));
	ppx->mypaths = ft_split(ppx->path_envp, ':');
	if (!ppx->mypaths)  //protection
		return (my_perror("Split error"));
	j = 0;
	while (ppx->mypaths[j])
	{
		ppx->mypaths[j] = ft_strjoin(ppx->mypaths[j], "/");
		if (!ppx->mypaths)
			return (my_perror("Strjoin error"));
		j++;
	}
	ppx->mycmdargs2 = ft_split(argv[2],' '); // ex ls -la. what if grep 'a'?
	if (!ppx->mycmdargs2)
		return (my_perror("Split error"));
	ppx->mycmdargs3 = ft_split(argv[3], ' ');
	if (!ppx->mycmdargs3)
		return (my_perror("Split error"));
	j = 0;
	while (ppx->mypaths[j])
	{
		ppx->cmd1 = ft_strjoin(ppx->mypaths[j], ppx->mycmdargs2[0]);
		if (!ppx->cmd1)
			return (my_perror("Strjoin error"));
		ppx->ok = access(ppx->cmd1, F_OK & X_OK);
		if (ppx->ok == 0)
			break;
		j++;
	}
	if (ppx->ok == -1)
		return (my_perror("Error"));
	i = 0;
	while (ppx->mypaths[i])
	{
		ppx->cmd2 = ft_strjoin(ppx->mypaths[i], ppx->mycmdargs3[0]);
		if (!ppx->cmd2)
			return (my_perror("Strjoin error"));
		ppx->ok = access(ppx->cmd2, F_OK & X_OK);
		if (ppx->ok == 0)
			break;
		i++;
	}
	if (ppx->ok == -1)
		return (my_perror("Error"));
	return (0);

	// mycmdargs = commandes trouvees dans /bin
	// cmd1 = path of the first command cat, ex /bin/cat
	// envoyer une erreur si la commande n'est pas valide
}
