/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:36:47 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/23 23:25:03 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	TODO : executing_minishell
	* condition when we only have redirection and no cmd
	
	TODO : loop
	* handle parse error with exit code
	* signal and check for history because it doesn't work

	TODO : overall
	* check leaks and fds open

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
		if (ft_strncmp("exit", line, 4) == 0)
		{
			handle_exit(mini);
			free(line);
			break ;
		}
		parsing_shell(mini, line);
		executing_minishell(mini);
		if (!line)
			add_history(line);
		free(line);
		reset_m_shell(mini);
	}
	// rl_clear_history();
}

// t_mini	*create_m_shell_env(char **envp)
// {
// 	t_mini	*m_shell;

// 	m_shell = malloc(sizeof(t_mini));
// 	if (!m_shell)
// 		return (NULL);
// 	m_shell->lst_env = create_lst_env(envp);
// 	m_shell->exit_code = 0;
// 	m_shell->nb_cmd = 0;
// 	m_shell->lst_cmd = NULL;
// 	return (m_shell);
// }

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

// int	main(int ac, char **av, char **envp)
// {
// 	(void) envp;
// 	(void) ac;
// 	(void) av;
// 	signal(SIGINT, test);
// 	// loop(envp);
// }

// int	main(int argc, char **argv, char **envp)
// {
// 	//init signal
// 	// loop(envp);
// 	t_mini *mini;
// 	mini = create_m_shell_env(envp);
// 	(void)argc;
// 	(void)argv;
// 	char **test = malloc(1000);

// 	test[0] = "/usr/bin/ls";
// 	test[1] = "test";
// 	test[2] = NULL;
// 	validate_cmd(test, mini->lst_env, mini);
// 	free_minishell(mini);
// 	free(test);
// 	return (0);
// }
