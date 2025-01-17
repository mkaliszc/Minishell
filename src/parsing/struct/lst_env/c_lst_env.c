/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_lst_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:24:00 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/17 01:35:37 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

t_env	*create_env(char *one_env)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->key = key_env(one_env);
	env->value = ft_strdup(ft_strchr(one_env, '=') + 1);
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
		lst_env_add_last(&lst_env, create_env(envp[i]));
		++i;
	}
	return (lst_env);
}

void	lst_env_add_last(t_env **lst_env, t_env *env)
{
	t_env	*tmp;

	if (!(*lst_env))
	{
		*lst_env = env;
		return ;
	}
	tmp = *lst_env;
	while (tmp)
	{
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
	tmp->next = env;
}

void	free_lst_env(t_env *lst_env)
{
	if (!lst_env)
		return ;
	free_lst_env(lst_env->next);
	if (lst_env->key)
		free(lst_env->key);
	if (lst_env->value)
		free(lst_env->value);
	free(lst_env);
}

void	create_one_lst_env(t_env *lst_env, char *export)
{
	t_env	*add_env;

	add_env = create_env(export);
	lst_env_add_last(&lst_env, add_env);
}
