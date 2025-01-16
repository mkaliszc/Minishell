/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 05:20:17 by albillie          #+#    #+#             */
/*   Updated: 2025/01/16 07:33:11 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_env_pwds(t_env *env, char *old_pwd)
{
	while (env)
	{
		if (ft_strcmp(env->key, "OLDPWD") == 0)
		{
			env->value = old_pwd;
		}
		if (ft_strcmp(env->key, "PWD") == 0)
		{
			env->value = getcwd(NULL, 0);
		}
		env = env->next;
	}
}
int	handle_cd(char **cmd, t_env **env)
{
	char *cwd = getcwd(NULL, 0);

	if (cmd_array_size(cmd) > 2)
	{
		ft_putstr_fd("cd: too many arguments\n", 2);
		return (1);
	}
	else if (!cmd[1])
	{
		if (chdir(getenv("HOME")) == -1)
		{
			ft_putstr_fd("cd: HOME not set\n", 2);
			return (1);
		}
	}
	else
	{
		if (chdir(cmd[1]) == -1)
		{
			ft_putstr_fd("cd: ", 2);
			perror(cmd[1]);
			return (1);
		}
	}
	update_env_pwds(*env, cwd);
	return (0);
}
