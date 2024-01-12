/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_mand.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:27:03 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/11 18:40:32 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_MAND_H
# define PIPEX_MAND_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <sys/types.h>
# include <string.h>
# include "../42_libft/libft.h"

# define ERRNO -1
# define CMD_NOT_FOUND -2
# define PATH_UNDEF -3
# define ALLOC_F 12
# define ENV_UNDEF -4

char	*getpath(char **env);
char	*get_fullcmd(char *cmd, char *path);
void	dbl_free(char **strs);
void	error(char *error, int flag);
void	usage_m(void);
void	execute(char *cmd, char **env);
int		safe_open(char *file_name, int flag);
void	safe_dup2(int oldfd, int newfd);

#endif
