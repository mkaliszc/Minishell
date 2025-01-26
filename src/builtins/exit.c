/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:35:06 by albillie          #+#    #+#             */
/*   Updated: 2025/01/26 03:12:22 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_exit(char **cmd, t_mini *mini)
{
	int	exit_code = 0;

	if (cmd_array_size(cmd) > 2)
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		mini->exit_code = 1;
	}
	else if (cmd[1])
	{
		exit_code = ft_atol(cmd[1]);
	}
	else
		exit_code = mini->exit_code;
	// exit_code = exit_code % 256;
	free_minishell(mini);
	exit(exit_code);
}
