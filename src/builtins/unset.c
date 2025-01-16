/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:16:21 by albillie          #+#    #+#             */
/*   Updated: 2025/01/16 17:15:11 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_unset(char **cmd, t_env **env)
{
	t_env *ptr = (*env);

	(void) cmd;
	while (ptr->next)
	{
		if (ft_strcmp(ptr->next->key, cmd[1]) == 0)
		{
			ptr->next = ptr->next->next;
		}
		ptr = ptr->next;
	}
}
