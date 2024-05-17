/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:27:44 by alassiqu          #+#    #+#             */
/*   Updated: 2024/05/17 21:36:15 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_left_valid_2(t_type type)
{
	return (type == AND || type == OR || type == PIPE
		|| type == L_PAREN);
}

int	is_right_valid_2(t_type type)
{
	return (type == S_QUOTE || type == D_QUOTE || type == ASTERISK
		|| type == DOLLAR || type == WORD || type == L_PAREN
		|| (type >= LL_REDIR && type <= R_REDIR));
}

int	checker_left_2(t_token *token)
{
	t_token	*tokens;

	tokens = token;
    if (!tokens->prev)
        return (0);
	if (tokens->type == L_PAREN && is_left_valid(tokens->prev->type))
	{
		printf(RED "minishell: syntax error near unexpected token `%s'\n" RESET,
			tokens->value);
		return (-1);
	}
	return (0);
}

int	checker_right_2(t_token *token)
{
	t_token	*tokens;

	tokens = token;
	if (is_pipe_or_and(tokens->type) && (!tokens->next->value
			|| is_right_valid(tokens->next->type)))
	{
		printf(RED "minishell: syntax error near unexpected token `%s'\n" RESET,
			tokens->value);
		return (-1);
	}
	return (0);
}