/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 11:11:46 by alassiqu          #+#    #+#             */
/*   Updated: 2024/06/03 12:42:46 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_env(char *var)
{
	if (!get_env_var(g_minishell->our_env, var))
		return (0);
	else
		return (ft_strlen(get_env_var(g_minishell->our_env, var)));
}

int	handle_dollar(char *s)
{
	char	*expand;
	char	*var;
	int		i;

	i = 0;
	expand = s;
	*expand++;
	if (ft_isspace(expand[i]))
	{
		s += 1;
		return (1);
	}
	while (!ft_isspace(expand[i]))
		i++;
	s += i + 1;
	var = ft_substr(expand, 0, i);
	if (!check_env(var))
		return (0);
	else
		return (check_env(var));
}

char	*expanding(char *s, char *expand, int i)
{
	char	*value;

	return (NULL);
}

char	*get_var(char *s)
{
	char	*expand;
	char	*var;
	int		i;

	i = 0;
	expand = s;
	*expand++;
	while (!ft_isspace(expand[i]))
		i++;
	s += i + 1;
	var = ft_substr(expand, 0, i);
	if (!var)
		return (NULL);
	return (var);
}

void	fill_value(char *s, char *value)
{
	char	*chunk;
	int		i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '$')
		{
			chunk = get_var(&s[i]);
			value[i] = ft_strjoin(value, get_env_var(g_minishell->our_env,
					chunk));
		}
		else
			value[i] = s[i];
	}
}

char	*helper_expander(char *s)
{
	char	*value;
	int		len;
	int		i;

	value = NULL;
	i = -1;
	len = 0;
	while (s[++i])
	{
		if (s[i] == '$')
			len += handle_dollar(&s[i]);
		else
			len++;
	}
	printf("==> %d\n", len);
	value = malloc((len + 1) * sizeof(char));
	if (!value)
		return (NULL);
	fill_value(s, value);
	return (value);
}

void	expander(void)
{
	t_token	*tokens;

	tokens = g_minishell->tokens;
	while (tokens)
	{
		if (tokens->type == WORD && ft_strchr(tokens->value, '$'))
			tokens->value = helper_expander(tokens->value);
		tokens = tokens->next;
	}
}
