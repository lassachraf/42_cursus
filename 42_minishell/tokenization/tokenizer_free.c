/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:58:45 by alassiqu          #+#    #+#             */
/*   Updated: 2024/06/05 18:26:56 by alassiqu         ###   ########.fr       */
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

void	append_string(t_token **tokens, char **line, t_type flag)
{
	t_token	*new;
	char	*value;
	char	*tmp;
	char	c;
	int		i;

	i = -1;
	tmp = *line;
	c = '"';
	if (flag == S_QUOTE)
		c = '\'';
	while (tmp[i] && tmp[i] != c)
		i++;
	value = ft_substr(*line, 0, i);
	new = new_token(value, WORD);
	add_token_back(tokens, new);
}

int handle_quotes(t_token **tokens, char **line)
{
	t_type	c;
	
	c = add_quote(tokens, line);
	append_string(tokens, line, c);
	if (*line && is_quote(**line))
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
