/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:16:21 by albillie          #+#    #+#             */
/*   Updated: 2025/01/19 05:24:38 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_env_part(t_env *env)
{
	if (env->key)
		free(env->key);
	if (env->value)
		free(env->value);
	free(env);
}

void	handle_unset(char **cmd, t_env **env)
{
	t_env	*ptr;
	t_env	*temp;

	if (!env || !*env || !cmd[1])
		return ;
	ptr = (*env);
	if (ft_strcmp(ptr->key, cmd[1]) == 0)
	{
		(*env) = ptr->next;
		free_env_part(ptr);
		return ;
	}
	while (ptr)
	{
		if (ptr->next && ft_strcmp(ptr->next->key, cmd[1]) == 0)
		{
			temp = ptr->next;
			ptr->next = ptr->next->next;
			free_env_part(temp);
			return ;
		}
		ptr = ptr->next;
	}
}
