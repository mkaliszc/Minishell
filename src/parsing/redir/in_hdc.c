/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_hdc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 04:21:27 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/21 05:01:34 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	redir_in(t_order_file **ord_f, char *cmd, int *i)
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
	create_order_file(ft_substr(cmd, start, end - start), IN));
}

void	redir_hdc(t_order_file **ord_f, char *cmd, int *i)
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
	create_order_file(ft_substr(cmd, start, end - start), HDC));
}

void	redir_in_hdc(t_order_file **ord_f, char *cmd, int *i)
{
	++*i;
	if (cmd[*i] == '<')
		redir_hdc(ord_f, cmd, i);
	else
		redir_in(ord_f, cmd, i);
}
