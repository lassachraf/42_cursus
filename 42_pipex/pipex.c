/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:52:58 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/06 16:25:36 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **argv, char **env, int *fd)
{
	int		infile;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
		ft_error("Inputfile");
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	ft_execute(argv[2], env);
}

void	parent_process(char **argv, char **env, int *fd)
{
	int		outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		ft_error("Outputfile");
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	ft_execute(argv[3], env);
}

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		ft_path_error(env);
		if (pipe(fd) == -1)
			ft_error("pipe");
		pid = fork();
		if (pid == -1)
			ft_error("fork");
		if (pid == 0)
			child_process(argv, env, fd);
		wait(NULL);
		parent_process(argv, env, fd);
	}
	else
	{
		ft_putstr_fd("Error: Bad arguments\n", 2);
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	}
	return (0);
}
