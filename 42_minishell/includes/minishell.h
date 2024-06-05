/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:09:59 by alassiqu          #+#    #+#             */
/*   Updated: 2024/06/05 18:28:06 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define READLINE_LIBRARY
# define RED "\033[1;31m"
# define ORANGE "\033[1;33m"
# define RESET "\033[0m"
# define PROMPT "✨ badashell$ "

# include "../libft/libft.h"
# include "builtins.h"
# include "parsing.h"
# include "tokenization.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

typedef struct s_env
{
	char			*key;
	char			*value;
	bool			visible;
	struct s_env	*next;
}					t_env;

typedef struct s_minishell
{
	char			*line;
	t_token			*tokens;
	t_env			*our_env;
	t_node			*ast;
	int				exit_status;
	int				nb_tokens;
}					t_minishell;

extern t_minishell	*g_minishell;

/* Builtins */

// Function that change current working directory "cd".
void				ft_cd(t_minishell *mini, char *path);

// Function that prints the input with/without newline "echo".
void				ft_echo(char **args);

// Function that prints the env "env".
void				ft_env(t_env *env);

// Function that exit shell "exit".
void				ft_exit(void);

// Function that export variable to the environment "export".
void				ft_export(void);

// Function that prints current working directory "pwd".
void				ft_pwd(t_env *env);

// Function that unset environment variable "unset".
void				ft_unset(void);

/* Builtins utils */

// Function that execute the builtins.
int					execute_builtins(t_minishell *mini, char **args);

// Function that checks if the command is a builtin or not.
bool				ft_is_builtin(char *arg);

/* Cleaning */

// Function that cleanup minishell.
void				cleanup_minishell(void);

/* Environments */

// Function that set environment variable.
void				set_env_var(t_env *env, char *var, char *new);

// Function that get the value of an environment variable.
char				*get_env_var(t_env *env, char *var);

// Function that duplicate env variable.
t_env				*dup_env(char **env);

// Function that add a new env variable.
void				add_env_var(t_env *env, char *key, char *value,
						bool visible);

// Function that clean the environment.
void				clear_env(void);

// Function that remove an element from the env.
void				delete_env_var(t_env **env, char *key);

/* Expanding */

// Main function to do expand.
void				expander(void);

// Function that skip single quote.
int					skip_quote(char *s, int *i);

// Function that get the variable and search for it in the environment.
char				*get_var(char *s, int *i);

// Function that return the length of the variable after expanding.
int					check_env(char *var);

// Function that process special cases while filling the new value.
void				process_special_cases(char *s, char *value, int *i, int *j);

// Function that allocate and fill the new value.
char				*fill_value(char *s, int size);

// Function that set the value after DOLLAR.
char				*fill_dollar(char *s, char *var, int size);

/* Parsing */

// The main function for parsing the input and return our AST structure.
// t_node				*parsing(void);

/* Signals */

// Function that handle signals.
void				signals(void);

/* Syntax */

// The function is the second phase of the detection of syntax error.
int					syntax_second_phase(t_token *token);

// The function is the third phase of the detection of syntax error.
int					syntax_third_phase(t_token *token);

// Function that check if the left expression is valid or not.
int					first_checker_left(t_token *token);

// Function that check if the right expression is valid or not.
int					first_checker_right(t_token *token);

// Function that get the number of parenthesis.
int					nb_paren(void);

// Function that get the number of the quotes.
int					nb_quotes(void);

// Function that checks if the current expression is a (PIPE || OR || AND).
int					is_pipe_or_and(t_type type);

// Function that checks if the left is valid or not.
int					is_left_valid3(t_type type);

// Function that checks if the right is valid or not.
int					is_right_valid3(t_type type);

// Function that checks if the right of parenthesis is valid or not.
int					check_right_parenthesis(t_token *token);

// Function that prints errors.
void				print_errors(char *message);

/* Tokenization */

// The main function that tokenizes the input string.
t_token				*tokenizer(void);

// Function that specifie the the type of the token.
t_token				*choose_token(char *value, char c);

// Function that append quote token to the list of token.
int					append_quotes(t_token **tokens, char **line);

// Function that append quotes and the string between them.
int handle_quotes(t_token **tokens, char **line);

// Function that return if the character is a quote or not.
int					is_quote(char c);

/* Debugging ones */
void				print_tokens(t_token *token);

#endif /* MINISHELL_H */