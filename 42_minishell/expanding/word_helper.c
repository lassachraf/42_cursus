/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 22:12:44 by alassiqu          #+#    #+#             */
/*   Updated: 2024/06/10 00:49:59 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	skip_quote(char *s, int *i)
{
	char	*str;
	int		j;

	str = s + *i;
	j = *i;
	*i += 1;
	str++;
	while (*str && *str != '\'')
	{
		*i += 1;
		str++;
	}
	*i += 1;
	return (*i - j);
}

char	*get_var(char *s, int *i)
{
	char	*expand;
	char	*var;
	int		j;

	j = 0;
	expand = &s[*i];
	expand++;
	if (!expand)
		return (NULL);
	if (!ft_strncmp(&expand[j], "?", 1) || !ft_strncmp(&expand[j], "_", 1)
		|| !ft_strncmp(&expand[j], "$", 1))
		j++;
	else
		while (expand[j] && !is_quote(expand[j]) && (ft_isalnum(expand[j])
				|| !ft_strncmp(&expand[j], "_", 1)))
			j++;
	*i += j;
	var = ft_substr(expand, 0, j);
	if (!ft_strncmp(var, "\0", 1))
		return (NULL);
	return (get_env_var(g_minishell->our_env, var));
}

int	check_env(char *var)
{
	if (!var)
		return (0);
	if (!get_env_var(g_minishell->our_env, var))
		return (0);
	else
		return (ft_strlen(get_env_var(g_minishell->our_env, var)));
}

void	process_special_cases(char *s, char *value, int *i, int *j)
{
	char	*var;
	int		k;

	if (!g_minishell->dq_flag && !ft_strncmp(&s[*i], "'", 1))
	{
		value[(*j)++] = s[*i];
		while (s[++(*i)] && s[*i] != '\'')
			value[(*j)++] = s[*i];
		value[(*j)++] = s[*i];
	}
	else if (s[*i] == '$' && s[*i + 1] && (ft_isalnum(s[*i + 1]) || s[*i
			+ 1] == '?' || s[*i + 1] == '_' || s[*i + 1] == '$'))
	{
		var = get_var(s, i);
		k = -1;
		if (var)
			while (var[++k])
				value[(*j)++] = var[k];
	}
	else
		value[(*j)++] = s[*i];
}

char	*fill_value(char *s, int size)
{
	char	*value;
	int		i;
	int		j;

	i = 0;
	j = 0;
	value = malloc(size * sizeof(char));
	if (!value)
		return (NULL);
	while (s[i])
	{
		process_special_cases(s, value, &i, &j);
		i++;
	}
	value[j] = '\0';
	return (value);
}
