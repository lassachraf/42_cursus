/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 11:11:46 by alassiqu          #+#    #+#             */
/*   Updated: 2024/06/04 16:36:30 by alassiqu         ###   ########.fr       */
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
	if (!ft_strncmp(&expand[j], "?", 1))
		j++;
	else
		while (expand[j] && ft_isalnum(expand[j]))
			j++;
	*i += j;
	var = ft_substr(expand, 0, j);
	if (!ft_strncmp(var, "\0", 1))
		return (NULL);
	return (get_env_var(g_minishell->our_env, var));
}

// void	process_special_cases(char *s, char *value, int *i, int *j)
// {
//     char	*var;
//     int		k;

//     if (s[*i] == '\'')
//     {
//         value[(*j)++] = s[*i];
//         while (s[++(*i)] && s[*i] != '\'')
//             value[(*j)++] = s[*i];
//     }
//     else if (s[*i] == '$' && s[1 + (*i)] && (ft_isalnum(s[*i + 1]) || s[*i + 1] == '?'))
//     {
//         var = get_var(s, i);
//         k = -1;
//         if (var)
//         {
//             while (var[++k])
//                 value[(*j)++] = var[k];
//         }
//     }
//     else
//     {
//         value[(*j)++] = s[*i];
//     }
// }

// char	*fill_value(char *s, int size)
// {
//     char	*value;
//     int		i;
//     int		j;

//     i = -1;
//     j = 0;
//     value = malloc(size * sizeof(char));
//     if (!value)
//         return (NULL);
//     while (s[++i])
//     {
//         process_special_cases(s, value, &i, &j);
//     }
//     value[j] = '\0';
//     return (value);
// }

char	*fill_value(char *s, int size)
{
	char	*value;
	char	*var;
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	value = malloc(size * sizeof(char));
	if (!value)
		return (NULL);
	while (s[++i])
	{
		if (s[i] == '\'')
		{
			value[j++] = s[i];
			while (s[++i] && s[i] != '\'')
				value[j++] = s[i];
		}
		if (s[i] == '$' && s[1 + i] && (ft_isalnum(s[i + 1]) || s[i
				+ 1] == '?'))
		{
			var = get_var(s, &i);
			k = -1;
			if (var)
				while (var && var[++k])
					value[j++] = var[k];
		}
		else
			value[j++] = s[i];
	}
	value[j] = '\0';
	return (value);
}

int	check_env(char *var)
{
	if (!get_env_var(g_minishell->our_env, var))
		return (0);
	else
		return (ft_strlen(get_env_var(g_minishell->our_env, var)));
}

int	handle_dollar(char *s, int *i)
{
	char	*expand;
	char	*var;
	int		j;

	j = 0;
	expand = s + *i;
	expand++;
	if (ft_isspace(expand[j]))
	{
		*i += 2;
		return (2);
	}
	if (!ft_strncmp(&expand[j], "?", 1))
		j++;
	else
		while (expand[j] && ft_isalnum(expand[j]))
			j++;
	*i += j;
	var = ft_substr(expand, 0, j);
	if (!check_env(var))
		return (0);
	else
		return (check_env(var));
}

char	*helper_expander(char *s)
{
	char	*value;
	int		len;
	int		i;

	value = NULL;
	i = -1;
	len = 0;
	if (s[0] == '\'')
		return (s);
	while (s[++i])
	{
		if (s[i] == '\'')
			len += skip_quote(s, &i);
		else if (s[i] == '$')
			len += handle_dollar(s, &i);
		else
			len++;
	}
	value = fill_value(s, (len + 1));
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
