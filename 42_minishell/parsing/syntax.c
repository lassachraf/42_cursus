/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:13:52 by alassiqu          #+#    #+#             */
/*   Updated: 2024/05/17 21:27:24 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token	*custome_tokens(void)
{
	t_token	*curr;
	t_token	*new;

	curr = g_minishell->tokens;
	while (curr->value)
	{
		if (curr->type != WHITESPACE)
		{
			new = new_token(curr->value, curr->type);
			add_token_back(&g_minishell->tokens, new);
		}
		curr = curr->next;
	}
	add_token_back(&g_minishell->tokens, new_token(NULL, END));
	return (new);
}

int	syntax_first_phase(t_token *token)
{
	if (checker_left(token) == -1)
		return (-1);
	if (checker_right(token) == -1)
		return (-1);
	return (0);
}

int	syntax_second_phase(t_token *token)
{
	
}


int	syntax(void)
{
	t_token	*token;

	token = custome_tokens();
    while (token)
    {
        if (syntax_first_phase(token) == -1)
            return (clear_token(&token), -1);
        if (syntax_second_phase(token) == -1)
            return (clear_token(&token), -1);
        // if (syntax_third_phase(token) == -1)
        //     return (clear_token(&token), -1);
		token = token->next;
    }
	clear_token(&token);
    return (0);
}
