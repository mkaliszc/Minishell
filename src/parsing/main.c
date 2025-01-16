/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:53:13 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/15 22:08:45 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/jojo.h"

int	main(int argc, char *argv[], char **envp)
{
	t_mini	*m_shell;

	(void)argc;
	(void)argv;
	m_shell = create_m_shell_env(envp);
	j_loop(m_shell);
	free_m_shell(m_shell);
	return (0);
}
