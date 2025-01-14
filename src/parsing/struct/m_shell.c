/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_shell.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:23:21 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/14 23:41:34 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_mini	*create_m_shell(char **envp, char *ln_cmd)
{
	t_mini *m_shell;

	m_shell = malloc(sizeof(t_mini));
	if (!m_shell)
		return (NULL);
	m_shell->lst_env = create_lst_env(envp);
	show_lst_env(m_shell->lst_env);
	return (m_shell);
}