/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_mand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:32:55 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/11 18:40:15 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_mand.h"

void	child_process(char *cmd, char **env, int outfile, int last)
{
	pid_t	child_pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error("pipe", ERRNO);
	child_pid = fork();
	if (child_pid == -1)
		error("fork", ERRNO);
	if (child_pid == 0)
	{
		close(fd[0]);
		if (last)
		{
			close(fd[1]);
			safe_dup2(outfile, STDOUT_FILENO);
		}
		else
			safe_dup2(fd[1], STDOUT_FILENO);
		execute(cmd, env);
	}
	else
	{
		close(fd[1]);
		safe_dup2(fd[0], STDIN_FILENO);
	}
}

int	main(int ac, char **av, char **env)
{
	int		infile;
	int		outfile;

	if (ac != 5)
		usage_m();
	infile = safe_open(av[1], 0);
	safe_dup2(infile, STDIN_FILENO);
	outfile = safe_open(av[ac - 1], 1);
	child_process(av[2], env, outfile, 0);
	child_process(av[3], env, outfile, 1);
	while (waitpid(-1, NULL, 0) != -1)
		;
	return (0);
}
