/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:36:47 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/20 05:57:13 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	loop(char **envp)
// {
// 	t_mini	*data;
// 	char	*line;

// 	while (true)
// 	{
// 		line = readline("Wildshell>");
// 		if (ft_strncmp("exit", line, 5) == 0)
// 		{
// 			handle_exit(data);
// 			free(line);
// 			break;
// 		}
// 		// ? data = parsing jojo
// 		executing_minishell(data);
// 		free(line);
// 	}
// }

t_mini	*create_m_shell_env(char**envp)
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

int	main(int argc, char **argv, char **envp)
{
	//init signal
	// loop(envp);
	t_mini *mini;
	mini = create_m_shell_env(envp);
	(void)argc;
	(void)argv;
	char **test = malloc(1000);

	test[0] = "ls";
	test[1] = "-l";
	test[2] = NULL;
	get_path(test, mini->lst_env, mini);
	printf("%d\n", mini->exit_code);
	execve("/usr/bin/ls", test, lst_to_char(mini->lst_env));
	free_minishell(mini);
	free(test);
	return (0);
}
