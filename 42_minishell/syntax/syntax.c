/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:13:52 by alassiqu          #+#    #+#             */
/*   Updated: 2024/06/06 21:05:41 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token	*custome_tokens(void)
{
	t_token	*curr;
	t_token	*new_list;
	t_token	*new;

	curr = g_minishell->tokens;
	new_list = NULL;
	while (curr != NULL && curr->value != NULL)
	{
		if (curr->type != WHITESPACE)
		{
			new = new_token(curr->value, curr->type);
			add_token_back(&new_list, new);
		}
		curr = curr->next;
	}
	add_token_back(&new_list, new_token(NULL, END));
	return (new_list);
}

int	syntax_first_phase(t_token *token)
{
	if (first_checker_left(token) == -1)
		return (-1);
	if (first_checker_right(token) == -1)
		return (-1);
	return (0);
}

int	general_check(void)
{
	if (nb_paren())
		return (-1);
	if (nb_quotes())
		return (-1);
	return (0);
}

int	syntax(void)
{
	t_token	*token;
	t_token	*temp;

	token = custome_tokens();
	temp = token;
	while (token)
	{
		if (syntax_first_phase(token) || syntax_second_phase(token)
			|| syntax_third_phase(token))
		{
			set_env_var(g_minishell->our_env, "?", ft_itoa(2));
			clear_token(&temp);
			return (-1);
		}
		token = token->next;
	}
	if (general_check() == -1)
	{
		set_env_var(g_minishell->our_env, "?", ft_itoa(2));
		return (clear_token(&temp), -1);
	}
	return (0);
}
