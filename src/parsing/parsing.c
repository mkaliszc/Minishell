/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 03:14:14 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/20 00:46:29 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	parsing_shell(t_mini *m_shell, char *ln_cmd)
{
	(void)m_shell;
	// char **cmd_splited;
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
	// cmd_splited = split_line(ln_cmd);
	// show_all_lst_env(m_shell->lst_env);
	// show_all_lst_env(m_shell->lst_env);
	// find_n_replace_var(m_shell, ln_cmd);
	// u_r_one_lst_env(m_shell->lst_env, ln_cmd);
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
