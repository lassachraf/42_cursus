/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:58:27 by alassiqu          #+#    #+#             */
/*   Updated: 2024/05/21 15:16:36 by alassiqu         ###   ########.fr       */
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
		printf("type ==> '%u'\n", token->type);
		token = token->next;
	}
}

int	main(int ac, char **av, char **env)
{
	(void)ac, (void)av;
	g_minishell = malloc(sizeof(t_minishell));
	if (!g_minishell)
		return (1);
	g_minishell->our_env = dup_env(env);
	signals();
	while (1)
	{
		g_minishell->line = readline(ORANGE PROMPT RESET);
		if (g_minishell->line[0])
			add_history(g_minishell->line);
		g_minishell->tokens = tokenizer();
		g_minishell->ast = parser();
		if (!g_minishell->ast)
			continue ;
		// execution();
		// clear_token(&g_minishell->tokens);
		free(g_minishell->line);
		// system("leaks minishell");
	}
	return (0);
}
