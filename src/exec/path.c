/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 01:20:06 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/20 03:52:10 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*validate_cmd(char **cmd, t_env *envp)
{
	if (cmd[0] == NULL)
		return (NULL);
	if (access(cmd[0], X_OK) == 0)
		return (cmd[0]);
	else
		return (get_path(cmd, envp));
}

char	*get_path(char **cmd, t_env *envp)
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

		return(ft_putstr_fd("Command not found", 2), NULL);
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
