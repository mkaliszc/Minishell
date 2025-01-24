/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 01:20:06 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/24 17:10:50 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	check_absolute_path(char **cmd, t_mini *mini)
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

static char	*get_path(char **cmd, t_env *envp)
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
		ft_printf_fd(2, "%s: No such file or directory\n", cmd[0]);
		exit(127);
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

char	*validate_cmd_path(char **cmd, t_env *envp, t_mini *mini)
{
	char	*path;

	if (!cmd[0])
		return (NULL);
	check_absolute_path(cmd, mini);
	path = get_path(cmd, envp);
	printf("\npath : %s\n", path);
	if (!path)
	{
		ft_printf_fd(2, "Command not found: %s\n", mini->lst_cmd->cmd[0]);
		exit(1);
	}
	return (path);
}
