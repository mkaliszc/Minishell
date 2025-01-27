/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:36:47 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/27 14:19:12 by jbergos          ###   ########.fr       */
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

// volatile sig_atomic_t	g_signal_received = 0;

void	loop(char **envp)
{
	t_mini	*mini;
	char	*line;

	mini = create_m_shell_env(envp);
	while (true)
	{
		// g_signal_received = 0;
		line = readline("$ ");
		if (!line)
			free_minishell(mini), exit(0);
		// g_signal_received = 1;
		parsing_shell(mini, line);
		// show_m_shell(mini);
		executing_minishell(mini);
		add_history(line);
		free(line);
		reset_m_shell(mini);
	}
}

// void	handle_sigint(int num)
// {
// 	(void)num;
// 	if (g_signal_received == 2)
// 	{
// 		write(1, "\n", 1);
// 		write(2, "DDDD\n", 5);

// 	}
// 	else
// 	{
// 		printf("tetst");
// 		write(1, "\n", 1);
// 		rl_on_new_line();
// 		rl_replace_line("", 0);
// 		rl_redisplay();
// 	}
// }

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	// struct sigaction sa;
	rl_outstream = stderr;
	// sa.sa_handler = handle_sigint;
	// sa.sa_flags = 0;
	// sigemptyset(&sa.sa_mask);
	// sigaction(SIGINT, &sa, NULL);
	// signal(SIGQUIT, SIG_IGN);
	loop(envp);
	return (0);
}
