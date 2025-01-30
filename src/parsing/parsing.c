/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 03:14:14 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/29 22:15:48 by mkaliszc         ###   ########.fr       */
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
}
