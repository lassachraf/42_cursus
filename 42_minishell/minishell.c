/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:58:27 by alassiqu          #+#    #+#             */
/*   Updated: 2024/06/14 13:18:30 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

t_minishell	*g_minishell;

void print_root(t_type type, int x)
{
       if(type == PIPE)
        {
            if (x == 1)
            printf("LEFT OF '|' ----> ");
            else if (x == 0)
                printf("RIGHT OF '|' ----> ");  
        }
        else if (type == OR)
        {
            if (x == 1)
            printf("LEFT OF '||' ----> ");
            else if (x == 0)
                printf("RIGHT OF '||' ----> ");
        }
        else if (type == AND)
        {
            if (x == 1)
            printf("LEFT OF '&&' ----> ");
            else if (x == 0)
                printf("RIGHT OF '&&' ----> ");
        }
        else if (type == L_PAREN)
        {
            if (x == 1)
            printf("LEFT OF '(' ----> ");
            else if (x == 0)
                printf("RIGHT OF '(' ----> ");
        }
}

void printAST(t_node* node , int x , t_type type) 
{
    t_type tmp;

    if (!node) return;

    tmp  = ERROR;
    if (node->type == STRING_NODE)
    {
        print_root(type, x);
        while (node->data.cmd)
        {
            printf("'%s' ", (char*)node->data.cmd->content);
            node->data.cmd = node->data.cmd->next;
        }
        printf("\n");
    }
	else if(node->type == PAIR_NODE)
	{
		print_root(type, x);
        if(node->data.pair.type == PIPE)
        {
            printf("------------------->PIPE<----------------------\n");
            tmp = PIPE;
        }
        else if (node->data.pair.type == OR)
        {
            printf("------------------->OR<----------------------\n");
            tmp = OR;
        } 
        else if (node->data.pair.type == AND)
        {
            printf("------------------->AND<----------------------\n");
            tmp = AND;
        }
        else if (node->data.pair.type == L_PAREN)
        {
            printf("L_PAREN\n");
            tmp = L_PAREN;
        }
        // if(node->data.pair.type <= 3)
        // {
            printAST(node->data.pair.left, 1 , tmp);
            printAST(node->data.pair.right, 0 , tmp);
        // }
        // else
        // {
        //     printAST(node->data.pair.left, 1 , tmp);
        //     printAST(node->data.pair.right, 0 , tmp);
        // }
    }
    else if (node->type == REDIR_NODE)
    {
        print_root(type, x);
        while(node->data.redir)
        {
            t_redir *new = node->data.redir->content;
            printf("REDIR NODE , name: '%s'\n",new->file);
            while (new->cmd)
            {
                printf("'%s' ", (char*)new->cmd->content);
                new->cmd = new->cmd->next;
            }
            printf("\n");
            node->data.redir = node->data.redir->next;
        }
    }
    else if(node->type == ERROR_NODE)
    {
        printf("add'%p', -ERROR -------> '%s",node ,node->data.error);
    }
}

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
	g_minishell->dq_flag = 0;
	g_minishell->our_env = dup_env(env);
	if (!g_minishell->our_env)
	{
		return (print_errors("dup_env failed !"), 0);
	}
	add_env_var(g_minishell->our_env, "?", "0", false);
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
		if (!g_minishell->line)
		{
			ft_putstr_fd("exit\n", 1);
            // cleanup();
			exit(0);
		}
		if (g_minishell->line[0])
			add_history(g_minishell->line);
		g_minishell->tokens = tokenizer();
		if (!g_minishell->tokens || syntax() == -1)
			continue ;
		expander();
		g_minishell->ast = parsing(g_minishell->tokens);
		if (!g_minishell->ast)
			continue ;
        printAST(g_minishell->ast, 1000 , 99);
		clear_token(&g_minishell->tokens);
		free(g_minishell->line);
	}
	clear_env();
    // free the g_mininshell :
    // clear_minishell();
	return (0);
}
