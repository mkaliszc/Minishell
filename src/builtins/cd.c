/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 05:20:17 by albillie          #+#    #+#             */
/*   Updated: 2025/01/16 06:03:27 by albillie         ###   ########.fr       */
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
		if (ft_strcmp(env->key, "PWD") == 0)
		{
			env->value = getcwd(buffer, 0);
		}
		env = env->next;
	}
}
int	handle_cd(char **cmd)
{
	if (cmd_array_size(cmd) > 2)
	{
		ft_putstr_fd("cd: too many arguments\n", 2);
		return (1);
	}
	else if (!cmd[1])
	{
		if (chdir(getenv("HOME")) == -1)
			ft_putstr_fd("cd: HOME not set\n", 2);
		return (1);
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
	return (0);
}
