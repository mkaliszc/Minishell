/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:36:47 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/26 08:17:32 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

/*
	TODO : overall
	* check leaks and fds open
	* signal

	? msg discord si doute

*/

volatile sig_atomic_t	g_signal_received = 0;

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

void	handle_sigint(int num)
{
	(void)num;
	g_signal_received = 2;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	struct sigaction sa;
	sa.sa_handler = handle_sigint;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
	signal(SIGQUIT, SIG_IGN);
	// signal(SIGINT, handle_sigint);
	loop(envp);
	return (0);
}
