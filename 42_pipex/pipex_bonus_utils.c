/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 20:07:39 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/10 09:57:42 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_arg_error(void)
{
	ft_putstr_fd("Error: Bad arguments!\n", 2);
	ft_putstr_fd("Ex: ./pipex_bonus <file1> <cmd1> <cmd2> <...> <file2>\n", 1);
	ft_putstr_fd("    ./pipex_bonus \"here_doc\" <LIMITER> \
	<cmd> <cmd1> <...> <file>\n", 1);
	exit(EXIT_SUCCESS);
}

int	open_file(char *argv, int i)
{
	int	fd;

	fd = 0;
	if (i == 0)
		fd = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (i == 1)
		fd = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 2)
		fd = open(argv, O_RDONLY, 0777);
	if (fd == -1)
		ft_error("Open file");
	return (fd);
}

void	ft_error(char *s)
{
	if (!*s)
		s = "ERROR";
	perror(s);
	exit(errno);
}
