/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:27:00 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/28 21:43:12 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* char	*get_name(void)
{
	static int i = 0;
	char	*name;
	char	*number;

	number = ft_itoa(i);
	if (!number)
		return (NULL);
	name = ft_strjoin("/tmp/here_doc_", number);
	free(number);
	i++;
	return (name);
}

char	*handle_here_doc(char *limiter)
{
	char	*name;
	int		tmp_fd;
	char	*line;
	// g_signal_received = 2;

	name = get_name();
	tmp_fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (tmp_fd < 0)
	{
		free(name);
		return (NULL);
	}
	while (true)
	{
		line = readline("> ");
		if (!line)
		{
			close(tmp_fd);
			break;
		}
		if (line == NULL)
			break ;
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
		{
			close(tmp_fd);
			free(line);
			return (name);
		}
		ft_putendl_fd(line, tmp_fd);
		free(line);
	}
	return (NULL);
} */

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
