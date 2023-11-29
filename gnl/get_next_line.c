/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:06:44 by alassiqu          #+#    #+#             */
/*   Updated: 2023/11/29 18:27:54 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_init_string(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char));
	if (!str)
		return (NULL);
	str[0] = 0;
	return (str);
}

void	shiftstr(char **static_buffer, size_t start)
{
	char	*tmp;

	tmp = *static_buffer;
	*static_buffer = ft_substr(*static_buffer, start, ft_strlen(*static_buffer));
	free(tmp);
}

int	ft_get_prev(char **static_buffer, int fd)
{
	char	*buf;
	ssize_t	ret;

	if (!BUFFER_SIZE || BUFFER_SIZE < 1 || fd < 0 || read(fd, 0, 0) < 0)
		return (0);
	if (!*static_buffer)
		*static_buffer = ft_init_string();
	if (!*static_buffer)
		return (0);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	ret = read(fd, buf, BUFFER_SIZE);
	while (ret)
	{
        // printf("ret => %lu \n", ret);
		buf[ret] = 0;
		*static_buffer = ft_strjoin(*static_buffer, buf);
        // printf("static buffer => %s \n", *static_buffer);
		if (ft_strchr(*static_buffer, '\n') >= 0)
			break ;
		ret = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	// printf("ending !!\n");
    return (1);
}

char	*get_next_line(int fd)
{
	static char		*static_buffer;
	char			*readed;
	int				cur;

    static_buffer = NULL;
	if (!ft_get_prev(&static_buffer, fd))
		return (NULL);
	cur = ft_strchr(static_buffer, '\n');
	if (cur >= 0)
	{
		readed = ft_substr(static_buffer, 0, cur + 1);
		shiftstr(&static_buffer, cur + 1);
	}
	else
	{
		readed = ft_substr(static_buffer, 0, ft_strlen(static_buffer));
		if (static_buffer)
            free(static_buffer);
        return (NULL);
	}
	if (readed && ft_strlen(readed) == 0)
	{
		free(readed);
		return (NULL);
	}
	return (readed);
}
