/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:27:00 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/28 22:31:30 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_open(t_data *info, t_order_file *cur, int exit_code)
{
	if (cur->type == APP && exit_code == 0)
	{
		if (info->out_fd > 1)
			close(info->out_fd);
		info->out_fd = open(cur->file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	}
	else if (cur->type == OUT && exit_code == 0)
	{
		if (info->out_fd > 1)
			close(info->out_fd);
		info->out_fd = open(cur->file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	}
	else if (cur->type == IN || cur->type == HDC)
	{
		if (info->in_fd > 0)
			close(info->in_fd);
		info->in_fd = open(cur->file, O_RDONLY);
	}
}

void	handle_file(t_mini *data, t_data *info, t_lst_cmd *tmp)
{
	bool			error;
	t_order_file	*cur;

	cur = tmp->order_file;
	error = false;
	while (cur)
	{
		handle_open(info, cur, data->exit_code);
		if ((info->in_fd == -1 || info->out_fd == -1) && error != true)
		{
			perror(cur->file);
			error = true;
			if (errno == 21)
				data->exit_code = 1;
			else
				data->exit_code = 126;
		}
		cur = cur->next;
	}
}
