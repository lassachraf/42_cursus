/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 09:42:13 by alassiqu          #+#    #+#             */
/*   Updated: 2024/05/21 15:16:59 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_ast	*parser(void)
{
	t_ast	*ast;

	ast = NULL;
	if (!g_minishell->tokens || syntax() == -1)
		return (NULL);
	return (ast);
}
