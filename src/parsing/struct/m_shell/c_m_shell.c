/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_m_shell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:23:21 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/15 23:59:02 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/jojo.h"

t_mini	*create_m_shell(char **envp, char *ln_cmd)
{
	t_mini	*m_shell;

	(void)ln_cmd;
	m_shell = malloc(sizeof(t_mini));
	if (!m_shell)
		return (NULL);
	m_shell->lst_env = create_lst_env(envp);
	// if (is_wrong_line(ln_cmd))
	// m_shell->lst_cmd = create_lst_cmd(ln_cmd);
	// show_lst_env(m_shell->lst_env);
	return (m_shell);
}

t_mini	*create_m_shell_env(char**envp)
{
	t_mini	*m_shell;
	m_shell = malloc(sizeof(t_mini));
	if (!m_shell)
		return (NULL);
	m_shell->lst_env = create_lst_env(envp);
	return (m_shell);
}

void	free_m_shell(t_mini *m_shell)
{
	free_lst_env(m_shell->lst_env);
	free(m_shell);
}
