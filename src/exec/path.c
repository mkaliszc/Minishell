/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 01:20:06 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/20 09:15:59 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*validate_cmd_path(char **cmd, t_env *envp, t_mini *data)
{
	char	*path;

	if (!cmd[0])
		return (NULL);
	check_absolute_path(cmd, data);
	path = get_path(cmd, envp, data);
	if (!path)
	{
		ft_printf_fd(2, "command not found: %s", data->lst_cmd->cmd[0]);
		exit(127);
	}
	return (path);
}

void	check_absolute_path(char **cmd, t_mini *mini)
{
	if (ft_strchr(cmd[0], '/'))
	{
		if (access(cmd[0], F_OK) < 0)
		{
			ft_printf_fd(2, "Command not found: %s\n", cmd[0]);
			free_minishell(mini);
			exit(127);
		}
		else if (access(cmd[0], X_OK) < 0)
		{
			ft_printf_fd(2, "Permission denied: %s\n", cmd[0]);
			free_minishell(mini);
			exit(126);
		}
	}
}

char	*get_path(char **cmd, t_env *envp, t_mini *mini)
{
	t_env	*cur;
	char	**all_paths;
	char	*tmp;
	char	*path;
	int		i;

	i = 0;
	cur = find_one_lst_env(envp, "PATH");
	if (cur == NULL)
	{
		mini->exit_code = 127;
		return(ft_printf_fd(2, "%s: No such file or directory\n", cmd[0]), NULL);
	}
	all_paths = ft_split(cur->value, ':');
	while (all_paths[i])
	{
		tmp = ft_strjoin(all_paths[i], "/");
		path = ft_strjoin(tmp, cmd[0]);
		free(tmp);
		if (access(path, X_OK) == 0)
			return (ft_free_char_tab(all_paths), path);
		free(path);
		i++;
	}
	return (ft_free_char_tab(all_paths), NULL);
}
