/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parenthesis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:27:44 by alassiqu          #+#    #+#             */
/*   Updated: 2024/05/19 21:35:25 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	nb_paren(void)
{
	t_token	*token;
	int		count;

	token = g_minishell->tokens;
	count = 0;
	while (token)
	{
		if (token->type == L_PAREN)
			count++;
		else if (token->type == R_PAREN)
			count--;
		token = token->next;
	}
	return (count);
}

int	is_right_valid2(t_type type)
{
	return (type == S_QUOTE || type == D_QUOTE || type == ASTERISK
		|| type == DOLLAR || type == WORD || type == L_PAREN
		|| (type >= LL_REDIR && type <= R_REDIR));
}

int	check_left_parenthesis(t_token *token)
{
	if (!(!token->prev || token->prev->type == L_PAREN
			|| is_pipe_or_and(token->prev->type)))
	{
		printf(RED "minishell(left): syntax error near unexpected token `('\n" RESET);
		return (-1);
	}
	else if (!token->next || !is_right_valid2(token->next->type))
	{
		printf(RED "minishell(right): syntax error near unexpected token `('\n" RESET);
		return (-1);
	}
	return (0);
}

int	syntax_third_phase(t_token *token)
{
	if (token->type == L_PAREN)
	{
		if (check_left_parenthesis(token) == -1)
			return (-1);
	}
	else if (token->type == R_PAREN)
	{
		if (check_right_parenthesis(token) == -1)
			return (-1);
	}
	return (0);
}

// General checks

// int    count;
// count = nb_paren();
// if (count > 0)
// {
// 	printf(RED "minishell: syntax error near unexpected token `('\n" RESET);
// 	return (-1);
// }
// else if (count < 0)
// {
// 	printf(RED "minishell: syntax error near unexpected token `('\n" RESET);
// 	return (-1);
// }