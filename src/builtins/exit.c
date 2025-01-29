/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:35:06 by albillie          #+#    #+#             */
/*   Updated: 2025/01/29 02:50:30 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			return (false);
		}
		i++;
	}
	return (true);
}

void	handle_exit(char **cmd, t_mini *mini)
{
	int	exit_code = 0;

	if (cmd[1])
	{
		if (!is_numeric(cmd[1]))
		{
			ft_printf_fd(2, "exit: %s: numeric argument required\n", cmd[1]);
			exit_code = 2;
			free_minishell(mini);
			exit(exit_code);
		}
		exit_code = ft_atol(cmd[1]);
	}
	else
		exit_code = mini->exit_code;
	if (cmd_array_size(cmd) > 2)
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		mini->exit_code = 1;
		return ;
	}
	if (exit_code < 0)
		exit_code += 256;
	exit_code %= 256;
	free_minishell(mini);
	printf("exit\n");
	exit(exit_code);
}
