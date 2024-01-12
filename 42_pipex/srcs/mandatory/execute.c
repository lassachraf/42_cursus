/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:32:34 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/11 18:48:25 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_mand.h"

char	*check_cmd(char *command, char **env)
{
	if (command == NULL)
		return (exit(EXIT_FAILURE), NULL);
	if (ft_strchr(command, '/') != NULL)
	{
		if (access(command, F_OK | X_OK) == 0)
			return (command);
		else
			return (NULL);
	}
	else
		return (get_fullcmd(command, getpath(env)));
	return (NULL);
}

void	execute(char *cmd, char **env)
{
	char	**command;
	char	*full_cmd;

	full_cmd = NULL;
	command = ft_split(cmd, ' ');
	if (command == NULL)
		error(NULL, ALLOC_F);
	full_cmd = check_cmd(command[0], env);
	if (full_cmd == NULL)
		return (dbl_free(command), exit(EXIT_FAILURE));
	execve(full_cmd, command, env);
	dbl_free(command);
	free(full_cmd);
	exit(EXIT_FAILURE);
}
