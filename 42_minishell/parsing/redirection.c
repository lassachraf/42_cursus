/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:38:34 by alassiqu          #+#    #+#             */
/*   Updated: 2024/05/15 20:09:41 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	single_redirect_left(t_type curr, t_type next)
{
	if (curr == 6 && (next == 6 || next == 8))
	{
		if (next == 6)
			printf(RED "minishell: syntax error near unexpected token `<'\n" RESET);
		else
			printf(RED "minishell: syntax error near unexpected token `newline`\n" RESET);
		return (-1);
	}
	else if (curr == 6 && next == 4)
	{
		printf(RED "minishell: syntax error near unexpected token `<<'\n" RESET);
		return (-1);
	}
	else if (curr == 6 && next == 5)
	{
		printf(RED "minishell: syntax error near unexpected token `>>'\n" RESET);
		return (-1);
	}
	else if (curr == 6 && next == 7)
	{
		printf(RED "minishell: syntax error near unexpected token `>'\n" RESET);
		return (-1);
	}
	else
		return (0);
}

int	single_redirect_right(t_type curr, t_type next)
{
	if (curr == 7 && (next == 7 || next == 8))
	{
		if (next == 7)
			printf(RED "minishell: syntax error near unexpected token `>>'\n" RESET);
		else
			printf(RED "minishell: syntax error near unexpected token `newline`\n" RESET);
		return (-1);
	}
	else if (curr == 7 && next == 4)
	{
		printf(RED "minishell: syntax error near unexpected token `<<'\n" RESET);
		return (-1);
	}
	else if (curr == 7 && next == 5)
	{
		printf(RED "minishell: syntax error near unexpected token `>>'\n" RESET);
		return (-1);
	}
	else if (curr == 7 && next == 6)
	{
		printf(RED "minishell: syntax error near unexpected token `<'\n" RESET);
		return (-1);
	}
	else
		return (0);
}

int	double_redirect_left(t_type curr, t_type next)
{
	if (curr == 4 && (next == 4 || next == 8))
	{
		if (next == 4)
			printf(RED "minishell: syntax error near unexpected token `<<'\n" RESET);
		else
			printf(RED "minishell: syntax error near unexpected token `newline`\n" RESET);
		return (-1);
	}
	else if (curr == 4 && next == 5)
	{
		printf(RED "minishell: syntax error near unexpected token `>>'\n" RESET);
		return (-1);
	}
	else if (curr == 4 && next == 6)
	{
		printf(RED "minishell: syntax error near unexpected token `<'\n" RESET);
		return (-1);
	}
	else if (curr == 4 && next == 7)
	{
		printf(RED "minishell: syntax error near unexpected token `>'\n" RESET);
		return (-1);
	}
	else
		return (0);
}

int	double_redirect_right(t_type curr, t_type next)
{
	if (curr == 5 && (next == 5 || next == 8))
	{
		if (next == 5)
			printf(RED "minishell: syntax error near unexpected token `>>'\n" RESET);
		else
			printf(RED "minishell: syntax error near unexpected token `newline`\n" RESET);
		return (-1);
	}
	else if (curr == 5 && next == 4)
	{
		printf(RED "minishell: syntax error near unexpected token `<<'\n" RESET);
		return (-1);
	}
	else if (curr == 5 && next == 6)
	{
		printf(RED "minishell: syntax error near unexpected token `<'\n" RESET);
		return (-1);
	}
	else if (curr == 5 && next == 7)
	{
		printf(RED "minishell: syntax error near unexpected token `>'\n" RESET);
		return (-1);
	}
	else
		return (0);
}

int	check_redirections(t_type curr, t_type next)
{
	if (double_redirect_left(curr, next) == -1)
		return (-1);
	if (double_redirect_right(curr, next) == -1)
		return (-1);
	if (single_redirect_left(curr, next) == -1)
		return (-1);
	if (single_redirect_right(curr, next) == -1)
		return (-1);
	return (0);
}
