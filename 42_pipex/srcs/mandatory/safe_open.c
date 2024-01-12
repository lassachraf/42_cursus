/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:33:08 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/11 18:39:01 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_mand.h"

int	safe_open(char *file_name, int flag)
{
	int	fd;

	if (flag == 0)
	{
		fd = open(file_name, O_RDONLY);
		if (fd == -1)
			error(file_name, ERRNO);
	}
	if (flag == 1)
	{
		fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd == -1)
			error(file_name, ERRNO);
	}
	if (flag == 2)
	{
		fd = open(file_name, O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (fd == -1)
			error(file_name, ERRNO);
	}
	return (fd);
}
