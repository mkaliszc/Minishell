/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_lst_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 04:57:02 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/26 05:48:42 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

int	str_is_space(char *export)
{
	int	i;

	i = 0;
	while (export[i])
	{
		if (export[i] == '=')
			return (1);
		++i;
	}
	return (0);
}

