/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:33:42 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/11 18:42:01 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

char	*check_cmd(char *command, char **env)
{
	if (NULL == command)
		return (exit(EXIT_FAILURE), NULL);
	if (NULL != ft_strchr(command, '/'))
	{
		if (0 == access(command, F_OK | X_OK))
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
	if (NULL == full_cmd)
		return (dbl_free(command), exit(EXIT_FAILURE));
	execve(full_cmd, command, env);
	dbl_free(command);
	free(full_cmd);
	exit(EXIT_FAILURE);
}
