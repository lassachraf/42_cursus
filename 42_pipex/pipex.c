/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:52:58 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/10 10:54:04 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *s)
{
	if (!*s)
		s = "ERROR";
	perror(s);
	exit(errno);
}

void	child_process(char *argv, char **env, int outfile, int flag)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		ft_error("Pipe");
	pid = fork();
	if (pid == -1)
		ft_error("Fork");
	if (pid == 0)
	{
		close(fd[0]);
		if (flag == 1)
		{
			close(fd[1]);
			dup2(outfile, STDOUT_FILENO);
		}
		else
			dup2(fd[1], STDOUT_FILENO);
		ft_execute(argv, env);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
	}
}

int	main(int argc, char **argv, char **env)
{
	int	infile;
	int	outfile;

	if (argc == 5)
	{
		ft_path_error(env);
		infile = open_file(argv[1], 2);
		outfile = open_file(argv[argc - 1], 1);
		dup2(infile, STDIN_FILENO);
		child_process(argv[2], env, outfile, 0);
		child_process(argv[3], env, outfile, 1);
		while (waitpid(-1, NULL, 0) != -1)
			;
	}
	else
		ft_arg_error();
	return (0);
}
