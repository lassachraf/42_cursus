/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:50:28 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/10 12:19:20 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include "42_libft/libft.h"

char	*search_for_path(char *cmd, char **env);
void	ft_execute(char *argv, char **env);
void	ft_free_paths(char **all_paths);
void	ft_path_error(char **env);
char	*ft_cmd_check(char *cmd);
void	ft_arg_error(void);
int		open_file(char *argv, int i);
void	ft_error(char *s);
void	safe_dup2(int oldfd, int newfd);

#endif