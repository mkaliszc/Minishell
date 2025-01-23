/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 03:14:14 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/23 04:33:25 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	parsing_shell(t_mini *m_shell, char *ln_cmd)
{
	if (empty_line(ln_cmd))
		return ;
	if (is_border_pipe(ln_cmd))
		return ;
	if (is_quote_closed(ln_cmd))
		return ;
	if (is_good_angle_bracket(ln_cmd))
		return ;
	if (is_dbl_pipe(ln_cmd))
		return ;
	add_lst_cmd(m_shell, ln_cmd);
	show_lst_cmd(m_shell->lst_cmd);
	// length_without_quote(m_shell->lst_cmd->cmd[0]);
	// length_o_var(m_shell->lst_cmd->cmd[0], m_shell->lst_env);
	// replace_o_var(m_shell->lst_cmd->cmd[0], m_shell->lst_env);
	reset_m_shell(m_shell);
}

void	j_loop(t_mini *m_shell)
{
	char	*line;

	while (true)
	{
		line = readline("Wildshell>");
		if (ft_strncmp("exit", line, 5) == 0)
		{
			free(line);
			break ;
		}
		parsing_shell(m_shell, line);
		free(line);
	}
}
