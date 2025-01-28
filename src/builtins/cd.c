/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 05:20:17 by albillie          #+#    #+#             */
/*   Updated: 2025/01/28 10:40:11 by albillie         ###   ########.fr       */
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

static void	handle_minus(t_mini *mini)
{
	t_env	*old_pwd;

	if (!find_one_lst_env(mini->lst_env, "OLDPWD"))
	{
		ft_putstr_fd("cd: OLDPWD not set\n", 2);
		mini->exit_code = 1;
		return ;
	}
	old_pwd = find_one_lst_env(mini->lst_env, "OLDPWD");
	printf("%s\n", old_pwd->value);
	chdir(old_pwd->value);
}

void	handle_cd(char **cmd, t_mini *mini)
{
	if (cmd_array_size(cmd) > 2)
	{
		ft_putstr_fd("cd: too many arguments\n", 2);
		mini->exit_code = 1;
		return ;
	}
	if (cmd[1] && ft_strcmp(cmd[1], "-") == 0)
	{
		handle_minus(mini);
	}
	else if (!cmd[1] || ft_strcmp(cmd[1], "~") == 0)
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
