/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:12:50 by alassiqu          #+#    #+#             */
/*   Updated: 2024/05/17 20:34:53 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_left_valid(t_type type)
{
	return (type == S_QUOTE || type == D_QUOTE || type == ASTERISK
		|| type == DOLLAR || type == WORD || type == R_PAREN);
}

int	is_right_valid(t_type type)
{
	return (type == S_QUOTE || type == D_QUOTE || type == ASTERISK
		|| type == DOLLAR || type == WORD || type == L_PAREN
		|| (type >= LL_REDIR && type <= R_REDIR));
}

int	is_pipe_or_and(t_type type)
{
	return (type == PIPE || type == OR || type == AND);
}

int	checker_left(t_token *token)
{
	t_token	*tokens;

	tokens = token;
	if (is_pipe_or_and(tokens->type) && (!tokens->prev
			|| is_left_valid(tokens->prev->type)))
	{
		printf(RED "minishell: syntax error near unexpected token `%s'\n" RESET,
			tokens->value);
		return (-1);
	}
	return (0);
}

int	checker_right(t_token *token)
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
