/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 22:12:44 by alassiqu          #+#    #+#             */
/*   Updated: 2024/06/13 14:04:34 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_var(char *s, int *i)
{
	char	*expand;
	char	*value;
	char	*var;
	int		j;

	j = 0;
	expand = s + *i + 1;
	if (!ft_strncmp(expand, "\0", 1) || ft_isspace(*expand))
		return (NULL);
	if (!ft_strncmp(expand, "$", 1))
		return (*i += 2, ft_strdup("$$"));
	if (!ft_strncmp(&expand[j], "?", 1) || !ft_strncmp(&expand[j], "_", 1))
		j++;
	else
		while (expand[j] && !is_quote(expand[j]) && (ft_isalnum(expand[j])
				|| !ft_strncmp(&expand[j], "_", 1)))
			j++;
	*i += j + 1;
	var = ft_substr(expand, 0, j);
	value = get_env_var(g_minishell->our_env, var);
	free(var);
	if (value)
		return (value);
	else
		return (NULL);
}

int	check_env(char *var)
{
	if (!var)
		return (-1);
	if (!get_env_var(g_minishell->our_env, var))
		return (-1);
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
		value[(*j)++] = s[*i++];
	}
	else if (s[*i] == '$' && s[*i + 1] && (ft_isalnum(s[*i + 1])
		|| s[*i + 1] == '_' || s[*i + 1] == '?'))
	{
		var = get_var(s, i);
		k = 0;
		if (var)
			while (var[k])
				value[(*j)++] = var[k++];
		else
			value[(*j)++] = s[*i++];
	}
	else
		value[(*j)++] = s[*i++];
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
	printf("s: %s\n", s);
	while (s[i])
		process_special_cases(s, value, &i, &j);
	value[j] = '\0';
	return (value);
}
