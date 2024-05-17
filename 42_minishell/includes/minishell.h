/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:09:59 by alassiqu          #+#    #+#             */
/*   Updated: 2024/05/17 20:30:08 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define READLINE_LIBRARY
# define RED "\033[1;31m"
# define ORANGE "\033[1;33m"
# define RESET "\033[0m"
# define PROMPT "✨✨ > badashell$ "

# include "../libft/libft.h"
# include "/Users/alassiqu/readline/include/readline/history.h"
# include "/Users/alassiqu/readline/include/readline/readline.h"
# include "builtins.h"
# include "parsing.h"
# include "tokenization.h"
# include <signal.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

typedef struct s_env
{
	char			*key;
	char			*value;
}					t_env;

typedef struct s_minishell
{
	char			*line;
	t_token			*tokens;
	t_env			**our_env;
	t_ast			*ast;
	int				exit_status;
	int				nb_tokens;
}					t_minishell;

extern t_minishell	*g_minishell;

/* Environments */
// Function that allocate in a safe way.
void				*safe_malloc(size_t size, void **data, int i);
// Function that set environment variable.
void				set_env_var(t_env **env, char *var, char *new);
// Function that get the value of an environment variable.
char				*get_env_var(t_env **env, char *var);
// Function that duplicate env variable.
t_env				**dup_env(char **env);

// The main function that tokenizes the input string.
t_token				*tokenizer(void);

/* Builtins */
// Function that prints the input with/without newline.
void				ft_echo(char **args);
// Function that change current working directory.
void				ft_cd(t_minishell *mini, char *path);
// Function that prints current working directory.
void				ft_pwd(t_env **env);
// Function that export variable to the environment.
void				ft_export(void);
// Function that unset environment variable.
void				ft_unset(void);
// Function that prints the env.
void				ft_env(t_env **env);
// Function that exit shell.
void				ft_exit(void);

/* Builtins utils */
// Function that execute the builtins.
int					execute_builtins(t_minishell *mini, char **args);
// Function that checks if the command is a builtin or not.
bool				ft_is_builtin(char *arg);

// Function that handle signals.
void				signals(void);

// Function that cleanup minishell.
void				cleanup_minishell(void);
// Function that clean the environment.
void				clear_env(void);

// Until here !

// The main function for parsing the input and return our AST structure.
t_ast				*parser(void);

// The function is the first phase of the detection of syntax error.
int					phase_1();

// Function that checks the redirections syntax.
int					check_redirections(t_type curr, t_type next);

// Functions that checks the pipes syntax.
int					check_pipes(t_type prev, t_type curr, t_type next);

t_token				*choose_token(char *value, char c);

// Function that check if the left expression is valid or not.
int					is_left_valid(t_type type);
int					checker_left(t_token *token);

// Function that check if the right expression is valid or not.
int					is_right_valid(t_type type);
int					checker_right(t_token *token);

// Function that checks if the current expression is a (PIPE || OR || AND).
int					is_pipe_or_and(t_type type);

#endif /* MINISHELL_H */