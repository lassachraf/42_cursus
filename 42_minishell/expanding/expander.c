/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 11:11:46 by alassiqu          #+#    #+#             */
/*   Updated: 2024/06/11 16:41:30 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	handle_dollar(char *s, int *i)
{
	char	*expand;
	char	*var;
	int		j;

	j = 0;
	expand = s + *i;
	if (!ft_strncmp(expand, "$$", 2))
		return (*i += 1, 2);
	if (!ft_strncmp(++expand, "\0", 1))
		return (1);
	printf("Handle_dollar: still expand\n");
	if (ft_isspace(expand[j]))
		return (*i += 2, 2);
	if (!ft_strncmp(&expand[j], "?", 1) || !ft_strncmp(&expand[j], "_", 1))
		j++;
	else
		while (expand[j] && !is_quote(expand[j]) && (ft_isalnum(expand[j])
				|| !ft_strncmp(&expand[j], "_", 1)))
			*i += j++;
	var = ft_substr(expand, 0, j);
	if (!check_env(var))
		return (j);
	else
		return (check_env(var));
}

char	*helper_expander(char *s)
{
	char	*value;
	int		len;
	int		i;

	i = -1;
	len = 0;
	while (s[++i])
	{
		if (s[i] == '$')
			len += handle_dollar(s, &i);
		else
			len++;
	}
	printf("helper_expander: len: %d\n", len);
	value = fill_value(s, len + 1);
	return (value);
}

void	expander(void)
{
	t_token	*tokens;

	tokens = g_minishell->tokens;
	while (tokens)
	{
		if (tokens->type == S_QUOTE)
		{
			tokens = tokens->next;
			while (tokens && tokens->type != S_QUOTE)
				tokens = tokens->next;
		}
		else if (tokens->type == WORD && ft_strchr(tokens->value, '$'))
		{
			if (tokens->prev && tokens->prev->type == D_QUOTE)
			{
				g_minishell->dq_flag = 1;
				tokens->value = helper_expander(tokens->value);
			}
			else
				tokens->value = helper_expander(tokens->value);
			g_minishell->dq_flag = 0;
		}
		tokens = tokens->next;
	}
}
