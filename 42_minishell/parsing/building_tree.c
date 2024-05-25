/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   building_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 20:53:21 by alassiqu          #+#    #+#             */
/*   Updated: 2024/05/25 17:28:17 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_node	*parse_cmd(t_token **tokens)
{
	t_list	*list;
	t_list	*new;
	int		x;

	x = 0;
	list = NULL;
	list = ft_lstnew((*tokens)->value);
	if (!list)
		return (NULL);
	while (*tokens && ((*tokens)->type == WORD || (*tokens)->type == WHITESPACE
			|| (*tokens)->type == R_PAREN))
	{
		if (x && (*tokens)->type != WHITESPACE && (*tokens)->type != R_PAREN)
		{
			new = ft_lstnew((*tokens)->value);
			if (!new)
				return (NULL);
			ft_lstadd_back(&list, new);
		}
		(*tokens) = (*tokens)->next;
		x++;
	}
	return (new_string_node(list));
}

t_node	*parse_pipe(t_token **tokens)
{
	t_node	*left;
	t_node	*right;
	t_type	type;

	left = NULL;
	right = NULL;
	if ((*tokens)->type == L_PAREN)
		(*tokens) = (*tokens)->next;
	if (*tokens && (*tokens)->type == WORD)
		left = parse_cmd(tokens);
	if (*tokens && (*tokens)->type == WHITESPACE)
		(*tokens) = (*tokens)->next;
	if (*tokens && ((*tokens)->type == PIPE || (*tokens)->type == AND
			|| (*tokens)->type == OR))
	{
		type = (*tokens)->type;
		(*tokens) = (*tokens)->next;
		if ((*tokens)->type == WHITESPACE || (*tokens)->type == L_PAREN)
			(*tokens) = (*tokens)->next;
		return (new_pair_node(left, parse_pipe(tokens), type));
	}
	else
		return (left);
}

t_node	*parse_seq(t_token **tokens)
{
	return (parse_pipe(tokens));
}

t_node	*parsing(t_token *tokens)
{
	t_node	*tmp;
	t_node	*res;
	int		x;

	x = 0;
	if (syntax() == -1)
		return (g_minishell->exit_status = 258,
			clear_token(&g_minishell->tokens), NULL);
	while (tokens)
	{
		tmp = parse_seq(&tokens);
		if (tokens->next)
			tokens = tokens->next;
	}
	// res = parse_pair(&tokens); // (a b)
	// printf("type is %s\n",tokens->value);
	return (res);
}
