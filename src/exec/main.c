/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:36:47 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/29 02:31:10 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

// volatile sig_atomic_t	g_signal_received = 0;


void	handle_sigint(int sig)
{
	(void) sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	loop(char **envp)
{
	t_mini	*mini;
	char	*line;
	int		exit_code;

	exit_code = 0;
	mini = create_m_shell_env(envp);
	while (true)
	{
		line = readline("$ ");
		if (!line)
		{
			exit_code = mini->exit_code;
			free_minishell(mini), exit(exit_code);
		}
		parsing_shell(mini, line);
		executing_minishell(mini);
		add_history(line);
		free(line);
		reset_m_shell(mini);
	}
}

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	signal(SIGINT, handle_sigint);
	// struct sigaction sa;
	// rl_outstream = stderr;
	// sa.sa_handler = handle_sigint;
	// sa.sa_flags = 0;
	// sigemptyset(&sa.sa_mask);
	// sigaction(SIGINT, &sa, NULL);
	// signal(SIGQUIT, SIG_IGN);
	loop(envp);
	rl_clear_history();
	return (0);
}
