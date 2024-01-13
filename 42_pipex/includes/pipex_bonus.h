/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:17:06 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/13 11:17:08 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
char	*get_next_line(void);
int		safe_open(char *file_name, int flag);
void	usage_b(void);
void	error(char *error, int flag);
void	execute(char *cmd, char **env);
void	dbl_free(char **strs);
void	safe_dup2(int oldfd, int newfd);

#endif
