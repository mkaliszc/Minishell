/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:36:47 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/25 21:34:16 by mkaliszc         ###   ########.fr       */
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
		if (ft_strcmp("exit", line) == 0)
		{
			handle_exit(mini);
			free(line);
			break ;
		}
		parsing_shell(mini, line);
		if (mini->exit_code == 0)
			executing_minishell(mini);
		add_history(line);
		free(line);
		reset_m_shell(mini);
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
