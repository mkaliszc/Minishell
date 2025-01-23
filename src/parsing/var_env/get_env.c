/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:20:23 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/23 04:11:28 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*get_env(t_env *lst_env, char *s)
{
	t_env	*tmp;

	if (!lst_env)
		return (NULL);
	tmp = lst_env;
	while (tmp)
	{
		if (ft_strcmp(s, tmp->key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}
