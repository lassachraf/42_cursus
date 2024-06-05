/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 22:21:08 by alassiqu          #+#    #+#             */
/*   Updated: 2024/06/05 17:47:49 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*fill_dollar(char *s, char *var, int size)
{
	char	*new;
	char	*value;
	int		i;
	int		k;

	(void)s;
	new = malloc(sizeof(char) * size);
	if (!new)
		return (NULL);
	i = -1;
	k = 0;
	value = get_env_var(g_minishell->our_env, var);
	while (value[++i])
		new[k++] = value[i];
	new[k] = '\0';
	return (new);
}
