/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 09:42:47 by alassiqu          #+#    #+#             */
/*   Updated: 2024/05/19 18:35:16 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct s_ast
{
	char			*value;
	struct s_ast	*left;
	struct s_ast	*right;
}					t_ast;

// Function that checks the syntax.
int					syntax(void);

#endif /* PARSER_H */