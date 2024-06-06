/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 09:42:47 by alassiqu          #+#    #+#             */
/*   Updated: 2024/06/06 16:39:16 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# define LEFT 0
# define RIGHT 1
# include "../libft/libft.h"
# include "tokenization.h"

typedef enum e_node
{
	ERROR_NODE = -1,
	PAIR_NODE,
	CHAR_NODE,
	STRING_NODE
}						e_node_type;

typedef struct s_node	t_node;

typedef struct s_tree
{
	t_type				type;
	t_node				*left;
	t_node				*right;
}						t_tree;

typedef union u_node_value
{
	t_tree				pair;
	t_list				*list;
	char				char_value;// unused yet
	const char			*error;// unused yet
}						u_node_value;

struct					s_node
{
	e_node_type			type;
	u_node_value		data;
};

t_node					*new_char_node(char c);

// t_node *new_pair_node(t_node *left, t_node *right);
t_node					*new_pair_node(t_node *left, t_node *right,
							t_type type);
t_node					*new_string_node(t_list *list);
t_node					*new_error_node(const char *msg);
t_node					*parsing(t_token *tokens);

// Function that checks the syntax.
int						syntax(void);

#endif /* PARSER_H */