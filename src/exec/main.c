/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:36:47 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/14 22:57:21 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	loop(char **envp)
{
	char	*line;

	while (true)
	{
		line = readline("Wildshell>");
		if (ft_strncmp("exit", line, 5) == 0)
		{
			// free minishell
			free(line);
			break;
		}
		// parsing jojo
		
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