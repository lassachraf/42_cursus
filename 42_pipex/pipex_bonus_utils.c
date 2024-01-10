/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 20:07:39 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/10 17:03:13 by alassiqu         ###   ########.fr       */
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
		ft_error("Opening file");
	return (fd);
}

void	ft_error(char *s)
{
	if (!*s)
		s = "ERROR";
	perror(s);
	exit(errno);
}

void	safe_dup2(int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) == -1)
		ft_error("dup2");
	close(oldfd);
}

void	get_heredoc_input(int argc, char *limiter, int *fd)
{
	char	*line;
	int		i;

	while (1)
	{
		i = 5;
		while (argc - i > 0)
		{
			ft_putstr_fd("pipe ", 1);
			i++;
		}
		ft_putstr_fd("heredoc> ", 1);
		custom_gnl(&line);
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
			exit(EXIT_SUCCESS);
		write(fd[1], line, ft_strlen(line));
		free(line);
	}
}
