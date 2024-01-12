/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:34:50 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/11 18:46:55 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

char	*get_next_line(void)
{
	ssize_t	byte;
	char	buffer[2];
	char	*line;
	char	*tmp;

	buffer[1] = '\0';
	line = malloc(1);
	if (!line)
		error(NULL, ALLOC_F);
	line[0] = '\0';
	while (1)
	{
		byte = read(0, buffer, 1);
		if (-1 == byte)
			break ;
		tmp = line;
		line = ft_strjoin(line, buffer);
		free(tmp);
		if ('\n' == buffer[0] || '\0' == buffer[0])
			return (line);
	}
	return (free(line), error("read", 0), NULL);
}
