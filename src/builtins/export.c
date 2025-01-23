/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:23:29 by albillie          #+#    #+#             */
/*   Updated: 2025/01/23 20:50:54 by albillie         ###   ########.fr       */
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

void	handle_export(char **cmd, t_env **env)
{
	int	i;

	if (cmd_array_size(cmd) < 2)
		return ;
	i = 1;
	while (cmd[i])
	{
		u_r_one_lst_env(*env, cmd[i]);
		i++;
	}

	// u_r_one_lst_env(*env, cmd[1]);
	// return ;
}
