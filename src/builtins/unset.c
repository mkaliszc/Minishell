/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:16:21 by albillie          #+#    #+#             */
/*   Updated: 2025/01/18 05:40:57 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_test(t_env *env)
{
	if (env->key)
		free(env->key);
	if (env->value)
		free(env->value);
	free(env);
}


void	handle_unset(char **cmd, t_env **env) // ! Do the while loop for each arg
{
	t_env *ptr = (*env);
	t_env *temp;
	if (!env || !*env)
		return ;
	if (ft_strcmp(ptr->key, cmd[1]) == 0)
	{
		(*env) = ptr->next;
		free_test(ptr);
		return ;
	}
	while (ptr)
	{
		if (ptr->next && ft_strcmp(ptr->next->key, cmd[1]) == 0)
		{
			temp = ptr->next;
			ptr->next = ptr->next->next;
			free_test(temp);
			return ;
		}
		ptr = ptr->next;
	}
}
