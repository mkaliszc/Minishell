/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:36:47 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/19 17:34:14 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	loop(char **envp)
{
	t_mini	*data;
	char	*line;

	while (true)
	{
		line = readline("Wildshell>");
		if (ft_strncmp("exit", line, 5) == 0)
		{
			handle_exit(data);
			free(line);
			break;
		}
		// ? data = parsing jojo
		executing_minishell(data);
		free(line);
	}
}

int	main(int argc, char **argv, char **envp)
{
	//init signal
	loop(envp);
	(void)argc;
	(void)argv;
	return (0);
}
