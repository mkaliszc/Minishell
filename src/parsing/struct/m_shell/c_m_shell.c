/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_m_shell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:23:21 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/20 02:12:10 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

void	add_lst_cmd(t_mini *m_shell, char *ln_cmd)
{
	char **cmd_split;
	(void)m_shell;
	cmd_split = split_cmd(ln_cmd);
	show_split(cmd_split);
	list_cmd_n_arg(cmd_split);
	// m_shell->lst_cmd
	free_split(cmd_split);
}

t_mini	*create_m_shell_env(char**envp)
{
	t_mini	*m_shell;
	m_shell = malloc(sizeof(t_mini));
	if (!m_shell)
		return (NULL);
	m_shell->lst_env = create_lst_env(envp);
	m_shell->exit_code = 0;
	m_shell->nb_cmd = 0;
	m_shell->lst_cmd = NULL;
	return (m_shell);
}

void	free_m_shell(t_mini *m_shell)
{
	free_lst_env(m_shell->lst_env);
	free(m_shell);
}
