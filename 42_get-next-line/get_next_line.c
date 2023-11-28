/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 08:40:50 by alassiqu          #+#    #+#             */
/*   Updated: 2023/11/28 09:14:29 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *str, char *buff)
{
	free(buff);
	return (str);
}

char	*ft_read(int fd, char *buff)
{
	char		*str;
	ssize_t		byte_readed;

	str = malloc(sizeof(char) * BUFFER_SIZE + 1);
	byte_readed = 1;
	while (byte_readed > 0)
	{
		byte_readed = read(fd, str, BUFFER_SIZE);
		if (byte_readed == -1)
		{
			free(str);
			return (NULL);
		}
		str[byte_readed] = '\0';
		buff = ft_free(ft_strjoin(buff, str), buff);
		if (ft_strchr(str, '\n'))
			break ;
	}
	free(str);
	return (buff);
}

char	*ft_get_line(char *buff)
{
	char	*line;
	int		i;

	i = 0;
	if (buff[0] == '\0')
		return (NULL);
	while (buff[i] != '\0' && buff[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (buff[i] != '\0' && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] != '\0' && buff[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_get_next_line(char *buff)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buff[i] != '\0' && buff[i] != '\n')
		i++;
	if (buff[i] == '\0')
	{
		free(buff);
		return (NULL);
	}
	line = malloc(sizeof(char) * (ft_strlen(buff) - i + 1));
	i++;
	while (buff[i] != '\0')
	{
		line[j] = buff[i];
		i++;
		j++;
	}
	line[j] = '\0';
	free(buff);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buff = ft_read(fd, buff);
	if (!buff)
		return (NULL);
	line = ft_get_line(buff);
	buff = ft_get_next_line(buff);
	return (line);
}

// int	main(void)
// {
// 	int	fd;

// 	fd = open("achraf.test", O_RDWR, 0777);
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// }
