/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 11:11:46 by alassiqu          #+#    #+#             */
/*   Updated: 2024/06/14 12:54:22 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	fill_dollar(char *s, int *i, char *new, int *j)
{
	char    *expand = s + *i;
	char	*expanded;
    char    *var;
	int		k;
	int		a;

	k = 0;
	a = 0;
    if (!ft_strncmp(&expand[1], "\0", 1))
    {
		(*i) += 1;
        new[*j] = expand[0];
		(*j)++;
        return ;
    }
	if (!ft_strncmp(&expand[1], "$", 1))
    {
		(*i) += 2;
		new[(*j)++] = expand[0];
		new[(*j)++] = expand[1];
        return ;
    }
	expand++;
	if (!ft_strncmp(expand, "?", 1))
        k = 1;
    else
    {
        while (expand[k])
        {
            if (ft_isalnum(expand[k]) || !ft_strncmp(&expand[k], "_", 1))
                k++;
            else
                break ;
        }
    }
	var = ft_substr(expand, 0, k);
	printf("var :: `%s`\n", var);
	expanded = get_env_var(g_minishell->our_env, var);
	free(var);
	(*i) += k + 1;
	if (!expanded)
		return ;
	else
	{
		while (expanded[a])
		{
			new[*j] = expanded[a++];
			(*j)++;
		}
	}
}

char	*new_value(char *s, int size)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = ft_malloc(g_minishell, size);
	if (!new)
		exit(1);
	while (s[i])
	{
		if (s[i] == '$')
			fill_dollar(s, &i, new, &j);
		else
			new[j++] = s[i++];
	}
	new[j] = '\0';
	printf("** new => `%s`\n\n", new);
	return (new);
}

char	*helper_expander(char *s)
{
	char	*new;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '$')
		{
			printf("** dollar **\n");
			handle_dollar(s, &i, &len);
		}
		else
		{
			printf("** else **\n");
			len++;
			i++;
		}
		printf("next char : `%s`\n", &s[i]);
	}
	printf("*--* len: %d *--*\n", len);
	new = new_value(s, len + 1);
	return (new);
}

void	helper(t_token *tokens)
{
	char	*new_value;

	new_value = NULL;
	if (tokens->prev && tokens->prev->type == D_QUOTE)
	{
		g_minishell->dq_flag = 1;
		new_value = helper_expander(tokens->value);
		if (new_value)
		{
			free(tokens->value);
			tokens->value = new_value;
		}
	}
	else
	{
		new_value = helper_expander(tokens->value);
		if (new_value)
		{
			free(tokens->value);
			tokens->value = new_value;
		}
	}
}

void	expanding(void)
{
	t_token	*tokens;

	tokens = g_minishell->tokens;
	while (tokens)
	{
		g_minishell->dq_flag = 0;
		if (tokens->type == S_QUOTE)
		{
			tokens = tokens->next;
			while (tokens && tokens->type != S_QUOTE)
				tokens = tokens->next;
		}
		else if (tokens->type == WORD && ft_strchr(tokens->value, '$'))
			helper(tokens);
		tokens = tokens->next;
	}
}

void	expander(void)
{
	pre_expander();
	expanding();
	post_expander();
	// printf("** after expanding: **\n");
	// print_tokens(g_minishell->tokens);
	// printf("\n\n");
}
