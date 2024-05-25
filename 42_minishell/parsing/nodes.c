/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:52:54 by alassiqu          #+#    #+#             */
/*   Updated: 2024/05/25 15:57:12 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_node	*new_char_node(char c)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
    if (!new)
        return (NULL);
	new->type = CHAR_NODE;
	new->data.char_value = c;
	return (new);
}

t_node	*new_string_node(t_list *list)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
    if (!new)
        return (NULL);
	new->type = STRING_NODE;
	new->data.list = list;
	return (new);
}

t_node	*new_pair_node(t_node *left, t_node *right, t_type type)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
    if (!new)
        return (NULL);
	new->type = PAIR_NODE;
	new->data.pair.left = left;
	new->data.pair.right = right;
	new->data.pair.type = type;
	return (new);
}

t_node	*new_error_node(const char *msg)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
    if (!new)
        return (NULL);
	new->type = ERROR_NODE;
	new->data.error = msg;
	return (new);
}
