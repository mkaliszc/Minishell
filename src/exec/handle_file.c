/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:27:00 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/19 03:07:45 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// todo open file in the order that they come not in then out

char	*handle_here_doc(char *limiter)
{
	int		tmp_fd;
	char	*line;

	tmp_fd = open(".tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (tmp_fd < 0)
		return ;
	while (true)
	{
		ft_printf("> ");
		line = get_next_line(0);
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
}

int	handle_out(t_mini *data)
{
	t_order_file	*cur;
	int				out_fd;

	cur = data->lst_cmd->order_file;
	out_fd = 1;
	while (cur)
	{
		if (cur->type == APP)
		{
			if (out_fd > 1)
				close(out_fd);
			out_fd = open(cur->file, O_CREAT | O_WRONLY | O_APPEND, 0644);
		}
		else if (cur->type == OUT)
		{
			if (out_fd > 1)
				close(out_fd);
			out_fd = open(cur->file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		}
		cur = cur->next;
	}
	return (out_fd);
}

int	handle_in(t_mini *data)
{
	t_order_file	*cur;
	int				in_fd;

	cur = data->lst_cmd->order_file;
	in_fd = 0;
	while (cur)
	{
		if (cur->type == HDC)
		{
			if (in_fd > 0)
				close(in_fd);
			in_fd = open(handle_here_doc(cur->file), O_RDONLY);
		}
		else if (cur->type == IN)
		{
			if (in_fd > 0)
				close(in_fd);
			in_fd = open(cur->file, O_RDONLY);
		}
		cur = cur->next;
	}
	return (in_fd);
}

int	handle_redir_no_pipe(t_mini *data)
{
	int	in_fd;
	int	out_fd;

	in_fd = handle_in(data);
	out_fd = handle_out(data);
	if (in_fd == -1 || out_fd == -1)
		return (perror("error while opening a file"), 1);
	if (in_fd != 0 && dup2(in_fd, STDIN_FILENO) < 0)
		return (perror("error while redirecting the entry"), 1);
	if (out_fd != 1 && dup2(out_fd, STDOUT_FILENO) < 0)
		return (perror("error while redirecting the output"), 1);
	if (in_fd != 0)
		close(in_fd);
	if (out_fd != 1)
		close(out_fd);
	return (0);
}

void	handle_redir(t_mini *data, int cmd_nbr, t_data *info)
{
	// * redirect to the pipe etc for last and first
}