/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 03:14:14 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/26 03:13:50 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	parsing_shell(t_mini *m_shell, char *ln_cmd)
{
	if (empty_line(ln_cmd))
		m_shell->exit_code = 0;
	else if (is_border_pipe(ln_cmd))
		m_shell->exit_code = 2;
	else if (is_quote_closed(ln_cmd))
		m_shell->exit_code = 2;
	else if (is_good_angle_bracket(ln_cmd))
		m_shell->exit_code = 2;
	else if (is_dbl_pipe(ln_cmd))
		m_shell->exit_code = 2;
	else
		add_lst_cmd(m_shell, ln_cmd);
	// show_m_shell(m_shell); ? ONLY FOR DEBUG
	// reset_m_shell(m_shell); ? ONLY FOR DEBUG
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
