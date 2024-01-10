/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 20:02:36 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/10 13:30:35 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	custom_gnl(char **line)
{
	char	*buffer;
	int		i;
	int		r;
	char	c;

	i = 0;
	r = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	r = read(0, &c, 1);
	while (r && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		r = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	free(buffer);
	return (r);
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
	char	*line;

	if (argc < 6)
		ft_arg_error();
	if (pipe(fd) == -1)
		ft_error("Pipe");
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		while (custom_gnl(&line))
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(EXIT_SUCCESS);
			write(fd[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(fd[1]);
		safe_dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

void	processes(char **argv, int argc, char **env, int outfile)
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
		ft_path_error(env);
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
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
		return (processes(argv, argc, env, outfile)0);
	}
	ft_arg_error();
}
