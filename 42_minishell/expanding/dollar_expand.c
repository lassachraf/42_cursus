/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_expand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 09:08:32 by alassiqu          #+#    #+#             */
/*   Updated: 2024/06/13 19:21:05 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	get_len(char *expand, int *j)
{
	if (!ft_strncmp(expand++, "$$", 1))
		return (3);
	if (*expand == '\0')
		return (1);
	if (ft_isspace(*expand))
		return (2);
	if (*expand == '?' || *expand == '_')
		*j = 1;
	else
	{
		while (expand[*j] && (!is_quote(expand[*j]) || ft_isalnum(expand[*j])
			|| expand[*j] == '_'))
			(*j)++;
	}
	return (0);
}

int	handle_dollar(char *s, int *i)
{
	char	*expand;
	char	*var;
	int		env_len;
	int		j;
	int		k;

	j = 0;
	expand = s + *i;
	k = get_len(expand, &j);
	if (k == 1)
		return (1);
	else if (k == 2)
		return (*i += 1, 2);
	else if (k == 3)
		return (*i += 2, 2);
	var = ft_substr(expand, 0, j);
	printf("substred var:: `%s`\n", var);
	*i += j + 1;
	env_len = check_env(var);
	free(var);
	if (env_len < 0)
		return (j);
	else
		return (env_len);
}
