/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_expand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 09:08:32 by alassiqu          #+#    #+#             */
/*   Updated: 2024/06/14 11:51:43 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handle_dollar(char *s, int *i, int *len)
{
	char	*expand = s + *i;
	char	*var;
	int		env_len;
	int		j;

	j = 0;
	expand++;
	if (!ft_strncmp(expand, "\0", 1))
	{
		*i += 1;
		(*len) += 1;
		return ;
	}
	if (!ft_strncmp(expand, "$", 1) || ft_isspace(*expand))
	{
		*i += 2;
		(*len) += 2;
		return ;
	}
	if (!ft_strncmp(expand, "?", 1))
		j = 1;
	else
	{
		while (expand[j])
		{
			if (ft_isalnum(expand[j]) || !ft_strncmp(&expand[j], "_", 1))
				j++;
			else
				break ;
		}
	}
	printf("j :: %d\n", j);
	var = ft_substr(expand, 0, j);
	env_len = check_env(var);
	free(var);
	(*i) += j + 1;
	if (env_len == -1)
		return ;
	else
	{
		(*len) += env_len;
		return ;
	}
}
