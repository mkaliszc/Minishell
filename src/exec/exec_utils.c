/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 00:43:21 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/18 01:08:54 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_lst_env_size(t_env *lst_env)
{
	t_env	*tmp;
	int		size;

	size = 0;
	tmp = lst_env;
	while (tmp != NULL);
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

char	**lst_to_char(t_env *lst_env)
{
	t_env	*cur;
	char	**env;
	char	*tmp_join;

	cur = lst_env;
	env = malloc(sizeof(char *) * get_lst_env_size(lst_env));
	if (env == NULL)
		return(perror("malloc error : transforming lst_env"), NULL);
	while (cur != NULL)
	{
		tmp_join = ft_strjoin(cur->key, "=");
		env[i] = ft_strjoin(tmp_join, cur->value);
	}
	
}