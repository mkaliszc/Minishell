/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 06:02:22 by albillie          #+#    #+#             */
/*   Updated: 2025/01/28 05:24:16 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_minishell(t_mini *mini)
{
	if (mini->lst_env)
		free_env_struct(mini->lst_env);
	if (mini->lst_cmd)
		free_cmd_struct(mini->lst_cmd);
	if (mini->data)
		free_data_struct(mini->data);
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
	t_order_file	*temp;

	if (!order_file)
		return ;
	while (order_file)
	{
		temp = order_file->next;
		if (order_file->file)
			free(order_file->file);
		free(order_file);
		order_file = temp;
	}
	free(order_file);
}

void	free_cmd_struct(t_lst_cmd *lst_cmd)
{
	t_lst_cmd	*temp;

	if (!lst_cmd)
		return ;
	while (lst_cmd)
	{
		temp = lst_cmd->next;
		if (lst_cmd->cmd)
			ft_free_char_tab(lst_cmd->cmd);
		if (lst_cmd->order_file)
			free_order_file_struct(lst_cmd->order_file);
		free(lst_cmd);
		lst_cmd = temp;
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
		free(data->pipe_fd);
	}
	free(data);
}
