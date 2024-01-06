/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:50:28 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/06 15:36:58 by alassiqu         ###   ########.fr       */
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

// Mandatory functions :

char	*search_for_path(char *cmd, char **env);
void	ft_execute(char *argv, char **env);
void	ft_error(char *s);
void	ft_free_paths(char **all_paths);
void	ft_path_error(char **env);

// Added ones for bonus part :

// void	ft_arg_error(void);

#endif