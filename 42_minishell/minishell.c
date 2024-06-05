/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:58:27 by alassiqu          #+#    #+#             */
/*   Updated: 2024/06/05 18:13:54 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

t_minishell	*g_minishell;

void	print_tokens(t_token *tokens)
{
	t_token	*token;

	token = tokens;
	while (token)
	{
		printf("value => '%s'\n", token->value);
		token = token->next;
	}
}

int	init_minishell(char **env)
{
	g_minishell = malloc(sizeof(t_minishell));
	if (!g_minishell)
		return (0);
	g_minishell->our_env = dup_env(env);
	g_minishell->exit_status = 0;
	signals();
	return (1);
}

int	main(int ac, char **av, char **env)
{
	(void)ac, (void)av;
	if (!init_minishell(env))
		return (1);
	while (1)
	{
		g_minishell->line = readline(ORANGE PROMPT RESET);
		if (g_minishell->line[0])
			add_history(g_minishell->line);
		g_minishell->tokens = tokenizer();
		if (syntax() == -1)
		{
			set_env_var(g_minishell->our_env, "?", ft_itoa(130));
			clear_token(&g_minishell->tokens);
			continue ;
		}
		printf("** Before Expanding: **\n");
		print_tokens(g_minishell->tokens);
		expander();
		printf("** After Expanding: **\n");
		print_tokens(g_minishell->tokens);
		clear_token(&g_minishell->tokens);
		// free(g_minishell->ast);
		free(g_minishell->line);
	}
	return (0);
}
