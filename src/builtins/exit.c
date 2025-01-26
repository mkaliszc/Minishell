/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:35:06 by albillie          #+#    #+#             */
/*   Updated: 2025/01/26 04:59:04 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// bool	is_numeric(char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (str[i] == '-' || str[i] == '+')
// 	{
// 		i++;
// 	}
// 	while (str[i])
// 	{
// 		/* code */
// 	}

// }


void	handle_exit(char **cmd, t_mini *mini)
{
	int	exit_code = 0;

	if (cmd_array_size(cmd) > 2)
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		exit_code = 1;
	}
	else if (cmd[1])
	{
		if (ft_atol(cmd[1]) == 0)
		{
			ft_printf_fd(2, "exit: %s: numeric argument required\n", cmd[1]);
			exit_code = 2;
		}
		else
		{
			exit_code = ft_atol(cmd[1]);
		}
	}
	// exit_code = mini->exit_code;
	if (exit_code < 0)
		exit_code += 256;
	exit_code %= 256;
	free_minishell(mini);
	exit(exit_code);
}
