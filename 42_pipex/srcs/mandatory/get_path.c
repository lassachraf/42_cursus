/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:32:47 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/11 18:39:14 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_mand.h"

char	*getpath(char **env)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	j = 0;
	if (!env)
		error(NULL, ENV_UNDEF);
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH", 4) == 0)
			break ;
		i++;
	}
	if (!env[i])
		error(NULL, PATH_UNDEF);
	while (env[i][j] != '=')
		j++;
	j++;
	path = ft_strdup(&env[i][j]);
	if (!path)
		error(NULL, ALLOC_F);
	return (path);
}
