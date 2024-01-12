/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:35:00 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/11 19:13:56 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

void	child_process(char *cmd, char **env, int outfile, int last)
{
	pid_t	child_pid;
	int		fd[2];

	if (-1 == pipe(fd))
		error("pipe", ERRNO);
	child_pid = fork();
	if (-1 == child_pid)
		error("fork", ERRNO);
	if (0 == child_pid)
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

void	get_heredoc_input(int ac, char *delimiter, int *end)
{
	char	*line;
	int		i;

	delimiter = ft_strjoin(delimiter, "\n");
	while (1)
	{
		i = 5;
		while (ac - i > 0)
		{
			ft_putstr_fd("pipe ", 1);
			i++;
		}
		ft_putstr_fd("heredoc> ", 1);
		line = get_next_line();
		if (ft_strncmp(line, delimiter, ft_strlen(line)) == 0)
			return (free(line), exit(EXIT_SUCCESS));
		write(end[1], line, ft_strlen(line));
		free(line);
	}
}

void	here_doc(char *delimiter, int ac)
{
	int		fd[2];
	pid_t	child_pid;

	if (ac < 6)
		usage_b();
	if (pipe(fd) == -1)
		error("pipe", ERRNO);
	child_pid = fork();
	if (child_pid == -1)
		error("fork", ERRNO);
	if (child_pid == 0)
	{
		close(fd[0]);
		get_heredoc_input(ac, delimiter, fd);
	}
	else
	{
		close(fd[1]);
		safe_dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

int	main(int ac, char **av, char **env)
{
	int		i;
	int		infile;
	int		outfile;

	if (0 == ft_strncmp(av[1], "here_doc", 9))
	{
		i = 3;
		outfile = safe_open(av[ac - 1], 2);
		here_doc(av[2], ac);
	}
	else
	{
		if (ac < 5)
			usage_b();
		i = 2;
		infile = safe_open(av[1], 0);
		outfile = safe_open(av[ac - 1], 1);
		safe_dup2(infile, STDIN_FILENO);
	}
	while (i < ac - 2)
		child_process(av[i++], env, outfile, 0);
	child_process(av[i++], env, outfile, 1);
	while (waitpid(-1, NULL, 0) != -1)
		;
	return (0);
}
