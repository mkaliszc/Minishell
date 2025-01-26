/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaveo <kaveo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:36:47 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/26 21:05:02 by kaveo            ###   ########.fr       */
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
		line = readline("Wildshell> ");
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
