/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:23:29 by albillie          #+#    #+#             */
/*   Updated: 2025/01/15 01:01:02 by albillie         ###   ########.fr       */
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
			printf("in condition\n");
			env->env = cmd;
			printf("%s\n", env->env);
		}
		env = env->next;
	}
	// printf("%s\n", cmd);
	// env_add_back(&env, env_lst_new(cmd));
	// print_env_list(env);
}
