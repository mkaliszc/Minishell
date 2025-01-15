/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:27:00 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/15 22:32:57 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	handle_out(t_mini *data) // * need to be close further in  the code 
{
	t_order_file	*cur;
	int				out_fd;

	cur = data->lst_cmd->order_file;
	out_fd = 0;
	while (cur)
	{
		if (cur->type == APP)
		{
			if (out_fd > 0)
				close(out_fd);
			out_fd = open(cur->file, O_CREAT | O_WRONLY | O_APPEND, 0644);
		}
		else if (cur->type == OUT)
		{
			if (out_fd > 0)
				close(out_fd);
			out_fd = open(cur->file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		}
		cur = cur->next;
	}
	return (out_fd);
}

int	handle_in(t_mini *data) // * need to be close further in the code
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