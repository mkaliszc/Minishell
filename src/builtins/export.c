/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:23:29 by albillie          #+#    #+#             */
/*   Updated: 2025/01/26 22:08:24 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_array_size(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

static void	exporting(t_mini *mini, char *export)
{
	t_env	*find;
	char	*key;
	int		i;

	i = 0;
	if (ft_strchr(export, '=') == NULL)
	{
		while (export[i])
		{
			if (!ft_isalpha(export[i]))
			{
				ft_printf_fd(2, " not a valid identifier\n");
				mini->exit_code = 1;
				return ;
			}
			i++;
		}
		return ;
	}
	if (!isalpha(export[0]))
	{
		ft_printf_fd(2, " not a valid identifier\n");
		mini->exit_code = 1;
		return ;
	}
	while (export[i] != '=')
	{
		if (!ft_isalnum(export[i]))
		{
			ft_printf_fd(2, " not a valid identifier\n");
			mini->exit_code = 1;
			break;
		}
		i++;
	}
	key = key_env(export);
	find = find_one_lst_env(mini->lst_env, key);
	i = 0;
	if (!find)
	{
		free(key);
		create_one_lst_env(mini->lst_env, export);
	}
	else
	{
		free(find->value);
		find->value = ft_strdup(ft_strchr(export, '=') + 1);
		free(key);
	}
}


void	handle_export(char **cmd, t_mini **mini)
{
	int	i;

	if (cmd_array_size(cmd) < 2)
		return ;
	if (cmd[1])
	{
		i = 1;
		while (cmd[i])
		{
			exporting(*mini, cmd[i]);
			i++;
		}
	}

}
