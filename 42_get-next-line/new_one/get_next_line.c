/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 10:46:34 by alassiqu          #+#    #+#             */
/*   Updated: 2023/11/26 18:13:47 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*get_next_line(int fd)
// {
// 	static char	buf[BUFFER_SIZE + 1];
// 	char		*line;
// 	int			count_bytes;
// 	int			flag_line;

// 	line = NULL;
// 	flag_line = 0;
// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	while (flag_line == 0)
// 	{
// 		flag_line = ft_line(buf, &line);
// 		if (flag_line == -1)
// 			return (free(&line));
// 		if (flag_line == 0)
// 		{
// 			count_bytes = read(fd, buf, BUFFER_SIZE);
// 			if (count_bytes == 0)
// 				flag_line == 1;
// 			else if (count_bytes <= 0)
// 				free(&line);
// 			buf[count_bytes] = '\0';
// 		}
// 	}
// 	return (line);
// }

// 1/ read from fd and add it to the linked list; done !
// 2/ extract from n to line;
// 3/ free the n;
// 4/ return the line;

void	ft_read(int fd, t_list *n, int *readed)
{
	char	*buffer;

	while (!ft_found_newline(n) && *readed != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return ;
		*readed = (int)read(fd, buffer, BUFFER_SIZE);
		if ((!n && *readed == 0) || *readed == -1)
		{
			free(buffer);
			return ;
		}
		buffer[*readed] = '\0';
		ft_add_to_lst(n, buffer, readed);
		free(buffer);
	}
}

int	ft_found_newline(t_list *n)
{
	t_list	current;
	int		i;

	if (!n)
		return (0);
	current = ft_lstlast(n);
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_add_to_lst(t_list *n, char *buffer, int readed)
{
	t_list	*new_node;
	t_list	*last;
	int		i;

	i = 0;
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (readed + 1));
	if (!new_node->content)
		return ;
	while (buf[i] && i < readed)
	{
		new_node->content[i] = buf[i];
		i++;
	}
	if (!*n)
	{
		n = new_node;
		return ;
	}
	last = ft_lstlast(n);
	last->next = new_node;
}

void	ft_extract_line(t_list *stash, char *line)
{
	int	i;
	int	j;

	if (!stash)
		return ;
	ft_generate_line(line, stash);
	if (!*line)
		return ;
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				break ;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

void	ft_generate_line(char **line, t_list *stash)
{
	int	i;
	int	len;

	len = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		stash = stash->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

char	*get_next_line(int fd)
{
	static t_list	*n;
	char			*line;
	int				readed;

	n = NULL;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	readed = 1;
	ft_read(fd, n, &readed);
	if (!*n)
		return (NULL);
	ft_extract_line();
}
