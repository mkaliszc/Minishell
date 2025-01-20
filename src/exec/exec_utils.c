/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 00:43:21 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/20 05:54:04 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_lst_env_size(t_env *lst_env)
{
	t_env	*tmp;
	int		size;

	size = 0;
	tmp = lst_env;
	while (tmp != NULL)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

char	**lst_to_char(t_env *lst_env)
{
	int		i;
	t_env	*cur;
	char	**env;
	char	*tmp_join;

	cur = lst_env;
	i = 0;
	env = malloc(sizeof(char *) * (get_lst_env_size(lst_env) + 1));
	if (env == NULL)
		return (perror("malloc error : transforming lst_env"), NULL);
	while (cur != NULL)
	{
		tmp_join = ft_strjoin(cur->key, "=");
		if (tmp_join == NULL)
			return (ft_free_char_tab(env), NULL);
		env[i] = ft_strjoin(tmp_join, cur->value);
		if (env[i] == NULL)
			return (ft_free_char_tab(env), NULL);
		free(tmp_join);
		i++;
		cur = cur->next;
	}
	env[i] = NULL;
	return (env);
}

