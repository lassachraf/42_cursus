/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:33:35 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/11 18:47:41 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

void	error(char *error, int flag)
{
	if (flag == ERRNO)
		perror(error);
	else if (flag == CMD_NOT_FOUND)
	{
		ft_putstr_fd(error + 1, 2);
		ft_putstr_fd(": command not found\n", 2);
		free(error);
		exit(127);
	}
	else if (flag == PATH_UNDEF)
		ft_putstr_fd("PATH: not found\n", 2);
	else if (flag == ALLOC_F)
		write(2, "Fatal: failed to allocate.\n", 27);
	else if (flag == ENV_UNDEF)
		ft_putstr_fd("ENVIRONMENT: not found", 2);
	exit(EXIT_FAILURE);
}

void	usage_b(void)
{
	ft_putstr_fd("usage: <infile> <cmd> <cmd1> <...> <outfile>\n", 2);
	ft_putstr_fd("usage: \"here_doc\" LIMITER <cmd> <cmd1> <...> <outfile>\
				\n", 2);
	exit(EXIT_FAILURE);
}
