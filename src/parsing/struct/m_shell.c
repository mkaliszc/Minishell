/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_shell.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:23:21 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/15 00:05:33 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/jojo.h"

t_mini	*create_m_shell(char **envp, char *ln_cmd)
{
	t_mini *m_shell;

	(void)ln_cmd;
	m_shell = malloc(sizeof(t_mini));
	if (!m_shell)
		return (NULL);
	m_shell->lst_env = create_lst_env(envp);
	show_lst_env(m_shell->lst_env);
	return (m_shell);
}