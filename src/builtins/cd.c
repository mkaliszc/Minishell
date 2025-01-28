/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 05:20:17 by albillie          #+#    #+#             */
/*   Updated: 2025/01/28 05:54:10 by albillie         ###   ########.fr       */
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

void	handle_home_event(t_mini *mini)
{
	t_env	*home;

	if (!find_one_lst_env(mini->lst_env, "HOME"))
	{
		ft_putstr_fd("cd: HOME not set\n", 2);
		mini->exit_code = 1;
		return ;
	}
	home = find_one_lst_env(mini->lst_env, "HOME");
	if (chdir(home->value) == -1)
	{
		ft_putstr_fd("cd: ", 2);
		perror(home->value);
		mini->exit_code = 1;
	}
}

void	handle_cd(char **cmd, t_mini *mini)
{
	if (cmd_array_size(cmd) > 2)
	{
		ft_putstr_fd("cd: too many arguments\n", 2);
		mini->exit_code = 1;
	}
	else if (!cmd[1] || ft_strncmp(cmd[1], "~", 1) == 0)
	{
		handle_home_event(mini);
	}
	else if (chdir(cmd[1]) == -1)
	{
		ft_putstr_fd("cd: ", 2);
		perror(cmd[1]);
		mini->exit_code = 1;
	}
	update_env_pwds(mini->lst_env);
}
