/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 01:20:06 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/18 02:59:40 by mkaliszc         ###   ########.fr       */
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
	cur = envp;
	while (find_one_lst_env(cur, "PATH") && cur != NULL)
		cur = cur->next;
	if (cur == NULL)
		return(ft_putstr_fd("environnement variable PATH not set", 2), NULL);
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
