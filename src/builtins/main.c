/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 08:04:18 by albillie          #+#    #+#             */
/*   Updated: 2025/01/16 14:57:04 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_array_size(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}


int main(int ac, char **av, char **envp)
{
	t_env *env;
	(void)ac;
	(void)av;
	char *line;
	env = create_lst_env(envp);
	while (true)
	{
		line = readline(GREEN"WildShell $ "END);
		char **command = ft_split(line, ' ');
		if (ft_strcmp(command[0], "pwd") == 0)
		{
			handle_pwd();
		}
		else if (ft_strcmp(command[0], "cd") == 0)
		{
			handle_cd(command, &env);
		}
		else if (ft_strcmp(command[0], "env") == 0)
		{
			handle_env(env);
		}
		else if (ft_strcmp(command[0], "echo") == 0)
		{
			handle_echo(command);
		}
		else if (ft_strcmp(command[0], "exit") == 0)
		{
			break; // ! Have to work on exit command right here.
		}
		else if (ft_strcmp(command[0], "export") == 0)
		{
			handle_export(command, &env);
		}
		else if (ft_strcmp(command[0], "unset") == 0)
		{
			handle_unset(command, &env);
		}
	}
}
