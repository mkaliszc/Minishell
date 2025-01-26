/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_lst_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 04:57:02 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/26 01:14:28 by albillie         ###   ########.fr       */
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

void	u_r_one_lst_env(t_env *lst_env, char *export)
{
	t_env	*find;
	char	*key;
	int		i;

	if (!str_is_space(export))
		return ;
	key = key_env(export);
	find = find_one_lst_env(lst_env, key);
	i = 0;
	if (!ft_isalpha(export[0]))
	{
		ft_printf_fd(2, " not a valid identifier\n");
		return ;
	}
	while (export[i] != '=')
	{
		if (!ft_isalnum(export[i]))
		{
			ft_printf_fd(2, " not a valid identifier\n");
			return;
		}
		i++;
	}
	if (!find)
	{
		free(key);
		create_one_lst_env(lst_env, export);
	}
	else
	{
		free(find->value);
		find->value = ft_strdup(ft_strchr(export, '=') + 1);
		free(key);
	}
}
