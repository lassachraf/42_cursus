/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:44:13 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/13 18:22:42 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int ft_ber_extension(char *argv)
{
    char    *new;

    if (access(argv, F_OK) == 0)
    {
       new = ft_strchr(argv, '.');
        if (!new)
            return (ft_errors("Input file error"), 0);
        else
        {
            if (ft_strncmp(new, ".ber", 5) == 0)
                return (1);
            else
                return (ft_errors("Extension file error"), 0);
        }
        return (0); 
    }
    else
        return (ft_errors("Map file doesn't exist"), 0);
}