/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_hdc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 04:21:27 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/23 04:40:45 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	redir_in(t_order_file **ord_f, char *cmd, int *i, t_env *env)
{
	int	start;
	int	end;

	while (cmd[*i] == ' ' && cmd[*i])
		++*i;
	start = *i;
	while ((cmd[*i] != ' ' && cmd[*i] != '<' && cmd[*i] != '>') && cmd[*i])
	{
		if (cmd[*i] == '"')
			while_d_quote(cmd, i);
		else if (cmd[*i] == '\'')
			while_s_quote(cmd, i);
		++*i;
	}
	end = *i;
	order_file_add_lst(ord_f, \
	create_order_file(replace_o_var(ft_substr(cmd, start, end - start), \
	env), IN));
}

void	redir_hdc(t_order_file **ord_f, char *cmd, int *i, t_env *env)
{
	int	start;
	int	end;

	++*i;
	while (cmd[*i] == ' ' && cmd[*i])
		++*i;
	start = *i;
	while ((cmd[*i] != ' ' && cmd[*i] != '<' && cmd[*i] != '>') && cmd[*i])
	{
		if (cmd[*i] == '"')
			while_d_quote(cmd, i);
		else if (cmd[*i] == '\'')
			while_s_quote(cmd, i);
		++*i;
	}
	end = *i;
	order_file_add_lst(ord_f, \
	create_order_file(replace_o_var(ft_substr(cmd, start, end - start), \
	env), HDC));
}

void	redir_in_hdc(t_order_file **ord_f, char *cmd, int *i, t_env *env)
{
	++*i;
	if (cmd[*i] == '<')
		redir_hdc(ord_f, cmd, i, env);
	else
		redir_in(ord_f, cmd, i, env);
}
