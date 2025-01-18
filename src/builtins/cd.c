/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 05:20:17 by albillie          #+#    #+#             */
/*   Updated: 2025/01/18 04:18:26 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_env_pwds(t_env *env)
{
	t_env	*pwd;

	pwd = find_one_lst_env(env, "PWD");
	while (env)
	{
		if (ft_strcmp(env->key, "OLDPWD") == 0)
		{
			free(env->value);
			env->value = ft_strdup(pwd->value);
		}
		if (ft_strcmp(env->key, "PWD") == 0)
		{
			free(env->value);
			env->value = getcwd(NULL, 0);
		}
		env = env->next;
	}
}
int	handle_cd(char **cmd, t_env **env)
{
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
	update_env_pwds(*env);
	return (0);
}
