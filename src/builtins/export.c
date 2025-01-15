/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:23:29 by albillie          #+#    #+#             */
/*   Updated: 2025/01/15 03:14:33 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_export(char *cmd, t_env *env)
{
	int i = 0;
	while (cmd[i] != '=')
		i++;
	while (env)
	{
		if (ft_strncmp(env->env, cmd, i) == 0)
		{
			env->env = cmd;
			return ;
		}
		env = env->next;
	}
}
