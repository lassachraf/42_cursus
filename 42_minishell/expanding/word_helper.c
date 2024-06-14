/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 22:12:44 by alassiqu          #+#    #+#             */
/*   Updated: 2024/06/14 11:36:37 by alassiqu         ###   ########.fr       */
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
		j = 1;
	else
		while (expand[j] && (!is_quote(expand[j]) || ft_isalnum(expand[j])
				|| !ft_strncmp(&expand[j], "_", 1)))
			j++;
	var = ft_substr(expand, 0, j);
	printf("var::: `%s`, j::: `%d`\n", var, j);
	*i += j + 1;
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

// void	process_special_cases(char *s, char *value, int *i, int *j)
// {
// 	char	*var;
// 	int		k;

// 	printf("** process_special_cases :analyser: **\n");
// 	printf("** :i: => :%d:\n", *i);
// 	printf("** :j: => :%d:\n", *j);
// 	if (!g_minishell->dq_flag && !ft_strncmp(&s[*i], "'", 1))
// 	{
// 		value[(*j)++] = s[(*i)++];
// 		while (s[(*i)] && s[*i] != '\'')
// 			value[(*j)++] = s[*i++];
// 		value[(*j)++] = s[(*i)++];
// 	}
// 	else if (s[*i] == '$' && s[*i + 1] && (ft_isalnum(s[*i + 1]) || s[*i
// 			+ 1] == '_' || s[*i + 1] == '?'))
// 	{
// 		printf(":i: `%d`\n", *i);
// 		var = get_var(s, i);
// 		printf(":i: `%d`\n", *i);
// 		printf(":var: `%s`\n", var);
// 		k = 0;
// 		if (var)
// 			while (var[k])
// 				value[(*j)++] = var[k++];
// 		else
// 			value[(*j)++] = s[*i];
// 	}
// 	else
// 		value[(*j)++] = s[*i];
// 	printf("** process_special_cases :conclusion: **\n");
// 	printf("** :i: => :%d:\n", *i);
// 	printf("** :j: => :%d:\n", *j);
// }

// char	*fill_value(char *s, int size)
// {
// 	char	*value;
// 	int		i;
// 	int		j;

// 	i = -1;
// 	j = 0;
// 	printf("** fill_value **\n");
// 	value = malloc(size * sizeof(char));
// 	if (!value)
// 		return (NULL);
// 	while (s[++i])
// 		process_special_cases(s, value, &i, &j);
// 	value[j] = '\0';
// 	return (value);
// }


