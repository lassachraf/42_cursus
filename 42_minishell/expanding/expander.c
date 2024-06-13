/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 11:11:46 by alassiqu          #+#    #+#             */
/*   Updated: 2024/06/13 19:19:15 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*helper_expander(char *s)
{
	char	*value;
	int		len;
	int		i;

	value = NULL;
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '$')
			len += handle_dollar(s, &i);
		else
			len++;
		i++;
	}
	printf("*--* len: %d *--*\n", len);
	printf("** filling finally **\n");
	// value = fill_value(s, len + 1);
	return (value);
}

void	helper(t_token *tokens)
{
	char	*new_value;

	new_value = NULL;
	if (tokens->prev && tokens->prev->type == D_QUOTE)
	{
		g_minishell->dq_flag = 1;
		new_value = helper_expander(tokens->value);
		if (new_value)
		{
			free(tokens->value);
			tokens->value = new_value;
		}
	}
	else
	{
		new_value = helper_expander(tokens->value);
		if (new_value)
		{
			free(tokens->value);
			tokens->value = new_value;
		}
	}
}

void	expanding(void)
{
	t_token	*tokens;

	tokens = g_minishell->tokens;
	while (tokens)
	{
		g_minishell->dq_flag = 0;
		if (tokens->type == S_QUOTE)
		{
			tokens = tokens->next;
			while (tokens && tokens->type != S_QUOTE)
				tokens = tokens->next;
		}
		else if (tokens->type == WORD && ft_strchr(tokens->value, '$'))
			helper(tokens);
		tokens = tokens->next;
	}
}

void	expander(void)
{
	printf("** before expanding: **\n");
	print_tokens(g_minishell->tokens);
	printf("\n\n");
	pre_expander();
	expanding();
	post_expander();
	printf("** after expanding: **\n");
	print_tokens(g_minishell->tokens);
	printf("\n\n");
}
