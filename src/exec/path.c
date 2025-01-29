/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 01:20:06 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/29 08:53:03 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static bool	check_perms(char *cmd)
{
	if (access(cmd, F_OK) == 0)
	{
		if (access(cmd, X_OK) == 0)
			return (true);
	}
	return (false);
}

char	*handle_when_slash(char **cmd, t_mini *mini)
{
	struct stat	buf;

	if (stat(cmd[0], &buf) == -1)
		(ft_printf_fd(2, "%s: No such file or directory\n", cmd[0]),
			free_minishell(mini), exit(127));
	else
	{
		if (check_perms(cmd[0]))
			return (cmd[0]);
		else
			(ft_printf_fd(2, "%s: No such file or directory\n", cmd[0]),
				free_minishell(mini), exit(127));
	}
}

char	*test_path(char **cmd, t_env *envp, t_mini *mini)
{
	char		*path;

	if (ft_strchr(cmd[0], '/'))
	{
		path = handle_when_slash(cmd, mini);
	}
	else
		path = get_path(cmd, envp, mini);
	if (path == NULL)
	{
		ft_printf_fd(2, "%s: command not found\n", cmd[0]);
		free_minishell(mini);
		exit(127);
	}
	else if (access(path, X_OK) == 0)
		return (path);
	else
	{
		perror(path);
		exit(126);
	}
}

char	*validate_cmd_path(char **cmd, t_env *envp, t_mini *mini)
{
	char		*path;
	struct stat	st;

	if (!cmd[0])
		return (NULL);
	path = test_path(cmd, envp, mini);
	if (stat(cmd[0], &st) == 0 && S_ISDIR(st.st_mode))
	{
		if (ft_strcmp(cmd[0], ".") == 0)
		{
			write(2, ".: filename argument required\n", 31);
			free_minishell(mini);
			exit(2);
		}
		else
		{
			write(2, cmd[0], ft_strlen(cmd[0]));
			write(2, " : is a directory\n", 19);
			free_minishell(mini);
			exit(126);
		}
	}
	return (path);
}
