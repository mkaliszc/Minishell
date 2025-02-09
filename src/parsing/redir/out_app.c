/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_app.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 04:23:17 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/24 02:57:21 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	redir_app(t_order_file **ord_f, char *cmd, int *i, t_mini *m_shell)
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
	m_shell), APP));
}

void	redir_out(t_order_file **ord_f, char *cmd, int *i, t_mini *m_shell)
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
	m_shell), OUT));
}

void	redir_out_app(t_order_file **ord_f, char *cmd, int *i, t_mini *m_shell)
{
	++*i;
	if (cmd[*i] == '>')
		redir_app(ord_f, cmd, i, m_shell);
	else
		redir_out(ord_f, cmd, i, m_shell);
}
