/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:27:20 by albillie          #+#    #+#             */
/*   Updated: 2025/01/14 11:26:52 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO have to work on echo depending of the commands

void	handle_echo(char **cmd)
{
	int	i;

	i = 1;
	if (!cmd[1])
		printf("\n");
	else if (ft_strncmp(cmd[1], "-n", 2) == 0)
	{
		while (cmd[1][i])
		{
			if (cmd[1][i] != 'n')
			{
				print_element(cmd);
				break;
			}
			i++;
		}
	}
	else
		print_element(cmd);
}

void	print_element(char **cmd)
{
	int	i;

	i = 1;
	printf("%s ", cmd[i++]);
	while (cmd[i])
	{
		printf("%s ", cmd[i]);
		i++;
	}
	printf("\n");
}
