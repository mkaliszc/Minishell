/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:36:47 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/20 08:41:34 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	loop(char **envp)
{
	t_mini	*mini;
	char	*line;

	while (true)
	{
		line = readline("Wildshell>");
		if (ft_strncmp("exit", line, 5) == 0)
		{
			handle_exit(mini);
			free(line);
			break;
		}
		mini = create_m_shell_env(envp);
		executing_minishell(mini);
		free(line);
	}
}

t_mini	*create_m_shell_env(char **envp)
{
	t_mini	*m_shell;
	m_shell = malloc(sizeof(t_mini));
	if (!m_shell)
		return (NULL);
	m_shell->lst_env = create_lst_env(envp);
	m_shell->exit_code = 0;
	m_shell->nb_cmd = 0;
	m_shell->lst_cmd = NULL;
	return (m_shell);
}

// int	main(int ac, char **av, char **envp)
// {
// 	(void) ac;
// 	(void) av;
// 	loop(envp);
// }

int	main(int argc, char **argv, char **envp)
{
	//init signal
	// loop(envp);
	t_mini *mini;
	mini = create_m_shell_env(envp);
	(void)argc;
	(void)argv;
	char **test = malloc(1000);

	test[0] = "/usr/bin/ls";
	test[1] = "test";
	test[2] = NULL;
	validate_cmd(test, mini->lst_env, mini);
	free_minishell(mini);
	free(test);
	return (0);
}
