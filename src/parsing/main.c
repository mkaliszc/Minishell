/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:53:13 by jbergos           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/01/15 01:11:56 by albillie         ###   ########.fr       */
=======
/*   Updated: 2025/01/15 22:08:45 by jbergos          ###   ########.fr       */
>>>>>>> d93908b23cbacf2054b56a5a4c16b5a51d9b4538
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/jojo.h"

<<<<<<< HEAD
// int main(int argc, char *arhv[], char **envp)
// {
// 	readshell(envp);
// 	return (0);
// }
=======
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
>>>>>>> d93908b23cbacf2054b56a5a4c16b5a51d9b4538
