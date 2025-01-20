/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 06:02:22 by albillie          #+#    #+#             */
/*   Updated: 2025/01/19 23:49:14 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_minishell(t_mini *mini)
{
	if (mini->lst_env)
		free_env_struct(mini->lst_env);
	if (mini->lst_cmd)
		free_cmd_struct(mini->lst_cmd);
	free(mini);
}

void	free_env_struct(t_env *lst_env)
{
	if (!lst_env)
		return ;
	free_lst_env(lst_env);
}

void	free_order_file_struct(t_order_file *order_file)
{
	if (!order_file)
		return ;
	while (order_file)
	{
		if (order_file->file)
			free(order_file->file);
		order_file = order_file->next;
	}
	free(order_file);
}

void	free_cmd_struct(t_lst_cmd *lst_cmd)
{
	if (!lst_cmd)
		return ;
	while (lst_cmd)
	{
		if (lst_cmd->cmd)
			ft_free_char_tab(lst_cmd->cmd);
		if (lst_cmd->order_file)
			free_order_file_struct(lst_cmd->order_file);
		lst_cmd = lst_cmd->next;
	}
	free(lst_cmd);
}

void	free_data_struct(t_data *data)
{
	if (!data)
		return ;
	if (data->pid)
		free(data->pid);
	if (data->pipe_fd)
	{
		close_all(data->pipe_fd);
		free(data->pipe_fd);
	}
}
