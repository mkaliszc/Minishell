/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 03:14:14 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/14 23:59:57 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/jojo.h"

t_mini	*parsing_shell(char **envp, char *ln_cmd)
{
	t_mini *m_shell;
	m_shell = create_m_shell(envp, ln_cmd);
	return (m_shell);
}

void		j_loop(char **envp)
{
	char *line;

	(void)envp;
	while (true)
	{
		line = readline("Wildshell>");
		if (ft_strncmp("exit", line, 5) == 0)
		{
			//free minishell
			free(line);
			break;
		}
		parsing_shell(envp, line);		
		free(line);
	}
}
