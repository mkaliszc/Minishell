/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:36:47 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/25 03:42:47 by albillie         ###   ########.fr       */
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
		line = readline("\e[0;32mWildshell> \e[0m");
		if (ft_strcmp("exit", line) == 0)
		{
			handle_exit(mini);
			free(line);
			break ;
		}
		parsing_shell(mini, line);
		// show_m_shell(mini);
		if (mini->exit_code == 0)
			executing_minishell(mini);
		add_history(line);
		free(line);
		reset_m_shell(mini);
		// show_m_shell(mini);
	}
	rl_clear_history();
}

// void	handle_sigint(void)
// {
// 	exit(1);
// }

int	main(int argc, char **argv, char **envp)
{
	// signal(SIGINT, handle_sigint);
	loop(envp);
	(void)argc;
	(void)argv;
	return (0);
}
