/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 05:20:17 by albillie          #+#    #+#             */
/*   Updated: 2025/01/14 13:37:02 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO Have to edit PWD and OLDPWD when changing directory
void	update_env_paths(t_env *env)
{
	char	*buffer;

	buffer = NULL;
	while (env)
	{
		if (ft_strncmp(env->env, "PWD=", 4) == 0)
		{
			env->env = getcwd(buffer, 0);
		}
		env = env->next;
	}
}
void	handle_cd(char **cmd, t_env **env)
{
	if (!cmd[1])
	{
		if (chdir(getenv("HOME")) == -1)
		{
			ft_putstr_fd("cd: HOME not set\n", 2); // Same message as bash when home is unset (unset HOME)
		}
	}
	else
	{
		if (chdir(cmd[1]) == -1)
		{
			ft_putstr_fd("cd: ", 2);
			perror(cmd[1]);
		}
		update_env_paths(&                                                                       env);
	}
}
