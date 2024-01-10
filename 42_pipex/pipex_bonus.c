/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 20:02:36 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/10 16:54:41 by alassiqu         ###   ########.fr       */
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
			safe_dup2(outfile, STDOUT_FILENO);
		}
		else
			safe_dup2(fd[1], STDOUT_FILENO);
		ft_execute(argv, env);
	}
	else
	{
		close(fd[1]);
		safe_dup2(fd[0], STDIN_FILENO);
	}
}

void	here_doc(char *limiter, int argc)
{
	pid_t	pid;
	int		fd[2];

	if (argc < 6)
		ft_arg_error();
	if (pipe(fd) == -1)
		ft_error("Pipe");
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		get_heredoc_input(argc, limiter, fd);
	}
	else
	{
		close(fd[1]);
		safe_dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

void	parent_process(char **argv, int argc, char **env, int outfile)
{
	child_process(argv[argc - 2], env, outfile, 1);
	while (waitpid(-1, NULL, 0) != -1)
		;
}

int	main(int argc, char **argv, char **env)
{
	int	i;
	int	infile;
	int	outfile;

	if (argc >= 5)
	{
		// ft_path_error(env);
		if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		{
			i = 3;
			outfile = open_file(argv[argc - 1], 0);
			here_doc(argv[2], argc);
		}
		else
		{
			i = 2;
			outfile = open_file(argv[argc - 1], 1);
			infile = open_file(argv[1], 2);
			safe_dup2(infile, STDIN_FILENO);
		}
		while (i < argc - 2)
			child_process(argv[i++], env, outfile, 0);
		return (parent_process(argv, argc, env, outfile), 0);
	}
	ft_arg_error();
}
