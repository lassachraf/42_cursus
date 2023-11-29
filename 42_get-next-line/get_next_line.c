/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 08:40:50 by alassiqu          #+#    #+#             */
/*   Updated: 2023/11/28 20:39:28 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *str, char *buff)
{
	printf("-- ft_free function ! -- \n");
	printf("%s \n", buff);
	if (buff)
	{
		printf("free buffer ! (ft_free) \n");
		free(buff);
	}
	return (str);
}

char	*ft_read(int fd, char *buff)
{
	printf("-- ft_read function ! -- \n");
	char		*str;
	ssize_t		byte_readed;

	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	byte_readed = 1;
	while (byte_readed > 0)
	{
		byte_readed = read(fd, str, BUFFER_SIZE);
		printf("-- byte readed => %lu --\n", byte_readed);
		// if (byte_readed == 0 && ft_strlen(buff) > 0)
		// {
		// 	printf("free str, return buffer ! (ft_read) \n");
		// 	return (free(str), buff);
		// }
		printf("allo");
		if (byte_readed == -1)
		{
			printf("hello");
			return (free(str), free(buff), NULL);
		}
		printf("cc");
		str[byte_readed] = '\0';
		printf("-- before joining => %s --\n", buff);
		buff = ft_free(ft_strjoin(buff, str), buff);
		printf("-- after joining => %s --\n", buff);
		if (ft_strchr(str, '\n') != NULL)
			break ;
	}
	free(str);
	printf("-- CIAO ! --\n\n");
	return (buff);
}

char	*ft_get_line(char *buff)
{
	printf("-- ft_get_line function ! -- \n");
	char	*line;
	int		i;
	int		check;

	check = 2;
	i = 0;
	if (buff[0] == '\0')
	{
		printf("return NULL 1 ! (ft_get_line)\n");
		return (NULL);
	}
	while (buff[i] != '\0' && buff[i] != '\n')
		i++;
	if (buff[i] == '\0')
		check = 1;
	line = malloc(sizeof(char) * i + check);
	if (!line)
		return (NULL);
	i = 0;
	while (buff[i] != '\0' && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (check == 2)
		line[i++] = '\n';
	line[i] = '\0';
	printf("-- CIAO ! --\n\n");
	return (line);
}

char	*ft_get_next_line(char *buff)
{
	printf("-- ft_get_next_line function ! --\n");
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buff[i] != '\0' && buff[i] != '\n')
		i++;
	if (buff[i] == '\0')
	{
		printf("free buffer 1 ! (ft_get_next_line) \n");
		free(buff);
		return (NULL);
	}
	line = malloc(sizeof(char) * (ft_strlen(buff) - i + 1));
	if (!line)
	{
		printf("free buffer 2 ! (ft_get_next_line)\n");
		return (free(buff), NULL);
	}
	i++;
	while (buff[i] != '\0')
		line[j++] = buff[i++];
	line[j] = '\0';
	free(buff);
	printf("-- CIAO ! --\n\n");
	return (line);
}

char	*get_next_line(int fd)
{
	printf("-- get_next_line function ! -- \n");
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
	{
		printf("malloc return NULL ! (get_next_line)\n");
		return (NULL);
	}
	buff = ft_read(fd, buff);
	if (!buff)
	{
		printf("read return NULL ! (get_next_line)\n");
		return (NULL);
	}
	line = ft_get_line(buff);
	printf("-- line => %s --\n", line);
	buff = ft_get_next_line(buff);
	printf("-- buff => %s --\n", line);
	printf("-- CIAO ! --\n\n");
	return (line);
}
