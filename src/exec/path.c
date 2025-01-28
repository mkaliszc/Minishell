/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 01:20:06 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/28 01:51:36 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	check_absolute_path(char **cmd, t_mini *mini)
{
	if (ft_strchr(cmd[0], '/'))
	{
		if (access(cmd[0], F_OK) < 0)
		{
			perror(cmd[0]);
			// ft_printf_fd(2, "%s: command not found\n", cmd[0]);
			free_minishell(mini);
			exit(127);
		}
		else if (access(cmd[0], X_OK) < 0)
		{
			perror(cmd[0]);
			// ft_printf_fd(2, "%s: Permission denied\n", cmd[0]);
			free_minishell(mini);
			exit(126);
		}
	}
}

static char	*get_path(char **cmd, t_env *envp, t_mini *mini)
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
		free_minishell(mini);
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
	path = get_path(cmd, envp, mini);
	if (!path)
	{
		struct stat st;

		if (stat(cmd[0], &st) == 0 && S_ISDIR(st.st_mode))
		{
			write(2, cmd[0], ft_strlen(cmd[0]));
			write(2, " : is a directory\n", 19);
			free_minishell(mini);
			exit(126);
		}
		else
		{
			write(2, cmd[0], ft_strlen(cmd[0]));
			write(2, " : command not found\n", 21);
			free_minishell(mini);
			exit(127);
		}
	}
	return (path);
}
