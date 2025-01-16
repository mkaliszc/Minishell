/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_lst_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 00:02:49 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/16 04:23:06 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	show_all_lst_env(t_env *lst_env)
{
	t_env	*tmp;

	if (!(lst_env))
		return ;
	tmp = lst_env;
	while (tmp)
	{
		printf("%s=", tmp->key);
		printf("%s\n", tmp->value);
		tmp = tmp->next;
	}
}

void	show_one_lst_env(t_env *lst_env, char *key)
{
	t_env	*tmp;

	if (!lst_env)
		return ;
	tmp = lst_env;
	while (tmp)
	{
		if (ft_strcmp(key, lst_env->key) == 0)
		{
			printf("%s\n", lst_env->value);
			return ;
		}
		tmp = tmp->next;
	}
}
