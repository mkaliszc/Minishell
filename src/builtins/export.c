/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:23:29 by albillie          #+#    #+#             */
/*   Updated: 2025/01/16 04:11:55 by albillie         ###   ########.fr       */
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
		if (ft_strcmp(env->key, cmd) == 0)
		{
			env->value = cmd;
			return ;
		}
		env = env->next;
	}
}
