/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:32:27 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/12 11:44:54 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_mand.h"

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

void	usage_m(void)
{
	ft_putstr_fd("Bad input: <infile> <cmd> <cmd1> <outfile>\n", 2);
	exit(EXIT_FAILURE);
}
