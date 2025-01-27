/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:23:29 by albillie          #+#    #+#             */
/*   Updated: 2025/01/26 23:40:25 by albillie         ###   ########.fr       */
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

static void	push_env_var(char *key, t_env *find, t_mini *mini, char *export)
{
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


static void	export_env_var(t_mini *mini, char *export)
{
	t_env	*find;
	char	*key;
	int i = 0;

	while (export[i] != '=')
	{
		if (!ft_isalnum(export[i]))
		{
			ft_printf_fd(2, "export: `%s`: not a valid identifier\n", export);
			mini->exit_code = 1;
			return ;
		}
		i++;
	}
	key = key_env(export);
	find = find_one_lst_env(mini->lst_env, key);
	push_env_var(key, find, mini, export);
}


static void	exporting(t_mini *mini, char *export)
{
	int		i;

	i = 0;
	if (ft_strchr(export, '=') == NULL)
	{
		while (export[i])
		{
			if (!ft_isalpha(export[i]))
			{
				ft_printf_fd(2, "export: `%s`: not a valid identifier\n", export);
				mini->exit_code = 1;
				return ;
			}
			i++;
		}
		return ;
	}
	if (!isalpha(export[0]))
	{
		ft_printf_fd(2, "export: `%s`: not a valid identifier\n", export);
		mini->exit_code = 1;
		return ;
	}
	export_env_var(mini, export);
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
