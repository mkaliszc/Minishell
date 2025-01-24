/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_m_shell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:25:56 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/24 05:27:17 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

void	show_m_shell(t_mini	*m_shell)
{
	if (!m_shell)
	{
		printf("Nothing to show\n");
		return ;
	}
	printf("exit code : %d , nb of pipe : %d\n", \
	m_shell->exit_code, m_shell->nb_cmd);
	printf("\n-----------------------------------------\n");
	if (m_shell->lst_cmd)
		show_lst_cmd(m_shell->lst_cmd);
}
