/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:24:00 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/15 00:28:43 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/jojo.h"

t_env	*create_env(char *one_env)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->env = one_env;
	env->next = NULL;

	return (env);
}

t_env	*create_lst_env(char **envp)
{
	t_env	*lst_env;
	int		i;

	i = 0;
	lst_env = NULL;
	while (envp[i])
	{
		lst_env_add_last(lst_env, create_env(envp[i]));
		++i;
	}
	return (lst_env);
}

void	lst_env_add_last(t_env *lst_env, t_env *env)
{
	t_env	*tmp;

	if (!(lst_env))
		lst_env = env;
	
	tmp = lst_env;
	while (tmp)
	{
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
	tmp->next = env;
}

void	show_lst_env(t_env *lst_env)
{
	t_env	*tmp;

	if (!(lst_env))
		return ;
	tmp = lst_env;
	while (tmp)
	{
		printf("%s\n", tmp->env);
		tmp = tmp->next;
	}
}
