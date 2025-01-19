/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:36:47 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/18 22:12:43 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data	*init_data_struct()
{
	t_data *data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	return (data);
}

void	loop(char **envp)
{
	t_mini	*data;
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
		data = init_data_struct();
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
