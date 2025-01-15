/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 03:14:14 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/15 01:43:06 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/jojo.h"

t_mini	*parsing_shell(char **envp, char *ln_cmd)
{
	t_mini	*m_shell;

	m_shell = create_m_shell(envp, ln_cmd);
	return (m_shell);
}

void	j_loop(char **envp)
{
	char	*line;
	t_mini	*m_shell;

	(void)envp;
	m_shell = NULL;
	while (true)
	{
		line = readline("Wildshell>");
		if (ft_strncmp("exit", line, 5) == 0)
		{
			//free minishell
			free(line);
			break ;
		}
		m_shell = parsing_shell(envp, line);
		free(line);
	}
	if (m_shell)
		free_m_shell(m_shell);
}
