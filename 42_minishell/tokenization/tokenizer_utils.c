/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:38:55 by alassiqu          #+#    #+#             */
/*   Updated: 2024/06/01 16:32:57 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_special(char c)
{
	return (c == '*' || c == '&' || c == '$');
}

int	is_separator(char *s)
{
	return (!ft_strncmp(s, "&&", 2) || *s == ' ' || *s == '\t' || *s == '<'
		|| *s == '>' || *s == '|' || *s == '(' || *s == ')');
}

void	skip_spaces(char **line)
{
	while (**line && ft_isspace(**line))
		(*line)++;
}

void	print_quote_err(char c)
{
	ft_putstr_fd("minishell: unexpected EOF while looking for matching '", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("'\n", 2);
}
