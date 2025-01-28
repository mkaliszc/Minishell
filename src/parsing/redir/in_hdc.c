/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_hdc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 04:21:27 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/28 04:06:14 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	redir_in(t_order_file **ord_f, char *cmd, int *i, t_mini *m_shell)
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
	m_shell), IN));
}

void	redir_hdc(t_order_file **ord_f, char *cmd, int *i, t_mini *m_shell)
{
	int	start;
	int	end;
	(void)m_shell;
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
	create_order_file(rep_n_quote(ft_substr(cmd, start, end - start)), HDC));
}

void	redir_in_hdc(t_order_file **ord_f, char *cmd, int *i, t_mini *m_shell)
{
	++*i;
	if (cmd[*i] == '<')
		redir_hdc(ord_f, cmd, i, m_shell);
	else
		redir_in(ord_f, cmd, i, m_shell);
}
