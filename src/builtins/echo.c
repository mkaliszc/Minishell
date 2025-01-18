/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:27:20 by albillie          #+#    #+#             */
/*   Updated: 2025/01/18 11:27:19 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_flag_here(char **cmd)
{
	int	i;

	i = 0;
	if (cmd[1][i] == '-')
	{
		i++;
	}
	else
		return (false);
	while (cmd[1][i])
	{
		if (cmd[1][i] != 'n')
		{
			return (false);
		}
		i++;
	}
	return (true);
}

void	print_elements(char **cmd, bool flag)
{
	int	i;

	if (flag)
		i = 2;
	if (!flag)
		i = 1;
	while (cmd[i])
	{
		while (cmd[i])
		{
			printf("%s", cmd[i]);
			if (cmd[i + 1])
				printf(" ");
			i++;
		}
	}
}

void	handle_echo(char **cmd)
{
	int	i;

	i = 1;
	if (!cmd[1])
		printf("\n");
	if (!is_flag_here(cmd))
	{
		while (cmd[i])
		{
			printf("%s ", cmd[i]);
			i++;
		}
		printf("\n");
		return ;
	}
	print_elements(cmd, true);
}
