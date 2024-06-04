/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:58:45 by alassiqu          #+#    #+#             */
/*   Updated: 2024/06/04 20:47:28 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int is_quote(char c)
{
	if (c == '"')
		return (1);
	else if (c == '\'')
		return (2);
	return (0);
}

int	add_quote(t_token **tokens, char **line)
{
	t_token	*new;
	char	*value;
	int		c;

	value = ft_substr(*line, 0, 1);
	new = choose_token(value, **line);
	c = is_quote(**line);
	*line += 1;
	add_token_back(tokens, new);
	return (c);
}

int	append_quotes(t_token **tokens, char **line)
{
	t_token	*new;
	char	*value;
	char	*tmp;
	int		type;
	int		i;

	i = 0;
	type = add_quote(tokens, line);
	tmp = *line;
	while (tmp[i] && is_quote(tmp[i]) != type)
		i++;
	value = ft_substr(tmp, 0, i);
	if (!value)
		return (0);
	new = new_token(value, WORD);
	if (!new)
		return (free(value), 0);
	*line += i;
	add_token_back(tokens, new);
	add_quote(tokens, line);
	return (1);
}

t_token	*choose_token(char *value, char c)
{
	t_token *new;

	new = NULL;
	if (c == '\'')
		new = new_token(value, S_QUOTE);
	else if (c == '"')
		new = new_token(value, D_QUOTE);
	else if (c == '*')
		new = new_token(value, ASTERISK);
	else if (c == '$')
		new = new_token(value, DOLLAR);
	else if (c == '&')
		new = new_token(value, AMPERSAND);
	return (new);
}

void	clear_token(t_token **tokens)
{
	t_token	*curr_node;
	t_token	*next;

	curr_node = *tokens;
	if (!curr_node)
		return ;
	while (curr_node)
	{
		free(curr_node->value);
		next = curr_node->next;
		free(curr_node);
		curr_node = next;
	}
	*tokens = NULL;
}
