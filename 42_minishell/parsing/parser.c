/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 09:42:13 by alassiqu          #+#    #+#             */
/*   Updated: 2024/06/01 17:40:58 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// void    remove_quotes(t_token tokens)
// {
//     t_token    *current;
//     t_token    tmp;

//     current = tokens;
//     while (current)
//     {
//         if (current->type == S_QUOTE || current->type == D_QUOTE)
//         {
//             tmp = current->next;
//             remove_token(tokens, current);
//             current = tmp;
//         }
//         else
//             current = current->next;
//     }
// }

// void    remove_whitespaces(t_token tokens)
// {
//     t_token    *current;
//     t_token    tmp;

//     current =tokens;
//     while (current)
//     {
//         if (current->type == WHITESPACE)
//         {
//             tmp = current->next;
//             remove_token(tokens, current);
//             current = tmp;
//         }
//         else
//             current = current->next;
//     }
//     return ;
// }