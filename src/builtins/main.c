/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 08:04:18 by albillie          #+#    #+#             */
/*   Updated: 2025/01/14 10:33:08 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	char *line;
	while (true)
	{
		line = readline(GREEN"WildShell $ "END);
		char **command = ft_split(line, ' ');
		if (ft_strncmp(command[0], "pwd", 3) == 0)
		{
			handle_pwd();
		}
		else if (ft_strncmp(command[0], "cd", 2) == 0)
		{
			handle_cd(command);
		}
		else if (ft_strncmp(command[0], "env", 3) == 0)
		{
			handle_env(envp);
		}
		else if (ft_strncmp(command[0], "echo", 4) == 0)
		{
			handle_echo(command);
		}
		else if (ft_strncmp(command[0], "exit", 4) == 0)
		{
			handle_echo(command);
		}
		ft_free_char_tab(command);
		free(line);
	}
}
