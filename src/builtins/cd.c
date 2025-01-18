/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 05:20:17 by albillie          #+#    #+#             */
/*   Updated: 2025/01/18 07:35:02 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_env_pwds(t_env *env)
{
	t_env	*old_pwd;

	old_pwd = find_one_lst_env(env, "PWD");
	while (env)
	{
		if (ft_strcmp(env->key, "OLDPWD") == 0)
		{
			free(env->value);
			env->value = ft_strdup(old_pwd->value);
		}
		if (ft_strcmp(env->key, "PWD") == 0)
		{
			free(env->value);
			env->value = getcwd(NULL, 0);
		}
		env = env->next;
	}
}

void	handle_home_event(t_env *env)
{
	t_env	*home;

	if (!find_one_lst_env(env, "HOME"))
	{
		ft_putstr_fd("cd: HOME not set\n", 2);
		return ;
	}
	home = find_one_lst_env(env, "HOME");
	if (chdir(home->value) == -1)
	{
		ft_putstr_fd("cd: ", 2);
		perror(home->value);
		return ;
	}
}

void	handle_cd(char **cmd, t_env *env)
{
	if (cmd_array_size(cmd) > 2)
	{
		ft_putstr_fd("cd: too many arguments\n", 2);
		return ;
	}
	else if (!cmd[1])
	{
		handle_home_event(env);
	}
	else if (chdir(cmd[1]) == -1)
	{
		ft_putstr_fd("cd: ", 2);
		perror(cmd[1]);
		return ;
	}
	update_env_pwds(env);
}
