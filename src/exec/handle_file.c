/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:27:00 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/27 07:20:48 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*handle_here_doc(char *limiter)
{
	int		tmp_fd;
	char	*line;
	// g_signal_received = 2;

	tmp_fd = open(".tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (tmp_fd < 0)
		return (NULL);
	while (true)
	{
		ft_putstr_fd("> ", 1);
		line = get_next_line(0);
		if (!line)
		{
			close(tmp_fd);
			break;
		}
		if (line == NULL)
			break ;
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
			&& line[ft_strlen(limiter)] == '\n')
		{
			close(tmp_fd);
			free(line);
			return (".tmp");
		}
		ft_putstr_fd(line, tmp_fd);
		free(line);
	}
	return (NULL);
}

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
	else if (cur->type == HDC)
	{
		if (info->in_fd > 0)
			close(info->in_fd);
		info->in_fd = open(handle_here_doc(cur->file), O_RDONLY);
	}
	else if (cur->type == IN)
	{
		if (info->in_fd > 0)
			close(info->in_fd);
		info->in_fd = open(cur->file, O_RDONLY);
	}
}

void	handle_file(t_mini *data, t_data *info, t_lst_cmd *tmp)
{
	t_order_file	*cur;

	cur = tmp->order_file;
	while (cur)
	{
		handle_open(info, cur, data->exit_code);
		if (info->in_fd == -1 || info->out_fd == -1)
			data->exit_code = 126;
		cur = cur->next;
	}
}
