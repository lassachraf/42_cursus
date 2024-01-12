/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fullcmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:32:41 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/11 18:39:21 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_mand.h"

char	*get_fullcmd(char *cmd, char *path)
{
	char	**paths;
	char	*full_cmd;
	int		i;

	i = 0;
	cmd = ft_strjoin("/", cmd);
	paths = ft_split(path, ':');
	if (!paths)
	{
		free(cmd);
		error(NULL, ALLOC_F);
	}
	while (paths[i] != NULL)
	{
		full_cmd = ft_strjoin(paths[i++], cmd);
		if (0 == access(full_cmd, F_OK))
			return (dbl_free(paths), free(cmd), full_cmd);
		free(full_cmd);
	}
	dbl_free(paths);
	error(cmd, CMD_NOT_FOUND);
	return (NULL);
}
