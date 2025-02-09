/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 00:43:21 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/29 22:34:50 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_close(t_data *data)
{
	if (data->out_fd != 1 && data->out_fd != -1)
		close(data->out_fd);
	if (data->in_fd != 0 && data->in_fd != -1)
		close(data->in_fd);
}

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
