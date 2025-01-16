/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:23:29 by albillie          #+#    #+#             */
/*   Updated: 2025/01/16 10:56:08 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_export(char **cmd, t_env **env)
{
	if (cmd_array_size(cmd) < 2)
		return (0);
	u_r_one_lst_env(*env, cmd[1]);
	return (0);
}
