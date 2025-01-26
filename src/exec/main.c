/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:36:47 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/26 03:38:16 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	TODO : overall
	* check leaks and fds open
	* signal

	? msg discord si doute

*/
void	loop(char **envp)
{
	t_mini	*mini;
	char	*line;

	mini = create_m_shell_env(envp);
	while (true)
	{
		line = readline("\e[1;32mWildshell> \e[0m");
		parsing_shell(mini, line);
		// show_m_shell(mini);
		executing_minishell(mini);
		add_history(line);
		free(line);
		reset_m_shell(mini);
	}
}

// void	handle_sigint(void)
// {
// 	exit(1);
// }

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	// signal(SIGINT, handle_sigint);
	loop(envp);
	return (0);
}
