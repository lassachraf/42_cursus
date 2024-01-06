/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:01:56 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/06 14:01:25 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*search_for_path(char *cmd, char **env)
{
	char	**all_paths;
	char	*first_part;
	char	*full_path;
	int		i;

	if (cmd[0] == '/')
		return (cmd);
	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == NULL)
		i++;
	ft_path_error(env[i]);
	all_paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (all_paths[i])
	{
		first_part = ft_strjoin(all_paths[i], "/");
		full_path = ft_strjoin(first_part, cmd);
		free(first_part);
		if (access(full_path, F_OK) == 0)
			return (ft_free_paths(all_paths), full_path);
		free(full_path);
		i++;
	}
	ft_free_paths(all_paths);
	return (NULL);
}

void	ft_execute(char *argv, char **env)
{
	char	**cmd;
	char	*path;
	int		i;

	i = -1;
	cmd = ft_split(argv, ' ');
	path = search_for_path(cmd[0], env);
	if (path == NULL)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		ft_error("Command not found");
	}
	if (execve(path, cmd, env) == -1)
		ft_error("Execution");
}

void	ft_error(char *s)
{
	if (!*s)
		s = "ERROR";
	perror(s);
	exit(errno);
}

void	ft_free_paths(char	**all_paths)
{
	int	i;

	i = -1;
	while (all_paths[++i])
		free(all_paths[i]);
	free(all_paths);
}

void	ft_path_error(char *env)
{
	if (ft_strnstr(env, "PATH", 4) == NULL)
	{
		ft_putstr_fd("Error: Unset PATH\n", 2);
		ft_error("Command not found");
	}
}
