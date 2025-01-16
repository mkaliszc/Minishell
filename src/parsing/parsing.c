/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 03:14:14 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/16 01:54:58 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/jojo.h"

void	parsing_shell(t_mini *m_shell, char *ln_cmd)
{
	(void)m_shell;
	char **cmd_splited;
	if (empty_line(ln_cmd))
		return ;
	cmd_splited = split_line(ln_cmd);
	// show_all_lst_env(m_shell->lst_env);
	// find_n_replace_var(m_shell, ln_cmd);
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
