/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:27:00 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/20 06:15:27 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*handle_here_doc(char *limiter)
{
	int		tmp_fd;
	char	*line;

	tmp_fd = open(".tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (tmp_fd < 0)
		return (NULL);
	while (true)
	{
		line = readline("> ");
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


void	handle_open(t_data *info, t_order_file *cur)
{
	if (cur->type == APP)
	{
		if (info->out_fd > 1)
			close(info->out_fd);
		info->out_fd = open(cur->file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	}
	else if (cur->type == OUT)
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

void	handle_file(t_mini *data, t_data *info)
{
	t_order_file	*cur;

	cur = data->lst_cmd->order_file;
	while (cur)
	{
		handle_open(info, cur);
		if (info->in_fd == -1 || info->out_fd == -1)
			data->exit_code = 126;
		cur = cur->next;
	}
}

int	handle_redir_no_pipe(t_mini *data, t_data *info)
{
	handle_file(data, info);
	if (info->in_fd == -1 || info->out_fd == -1 || data->exit_code == 126)
		return (perror("error while opening a file"), 1);
	if (info->in_fd != 0 && dup2(info->in_fd, STDIN_FILENO) < 0)
		return (perror("error while redirecting the entry"), 1);
	if (info->out_fd != 1 && dup2(info->out_fd, STDOUT_FILENO) < 0)
		return (perror("error while redirecting the output"), 1);
	if (info->in_fd != 0)
		close(info->in_fd);
	if (info->out_fd != 1)
		close(info->out_fd);
	return (0);
}

// void	handle_redir(t_mini *data, int cmd_nbr, t_data *info)
// {
// 	if(info->in_fd == 0 && cmd_nbr != 0)
// 	{
// 		if (dup2(info->pipe_fd + 2 * cmd_nbr, STDIN_FILENO))
// 		{
// 			// ! perror etc
// 		}
// 	}
// 	if (info->out_fd == 1 && cmd_nbr < data->nb_cmd)
// 	{
// 		if (dup2(info->pipe_fd + 2 * cmd_nbr, STDOUT_FILENO))
// 		{
// 			// ! perror etc
// 		}
// 	}
// 	if (cmd_nbr == 0)
// 	{
// 		// * handle redirect for the first child
// 	}
// 	if (cmd_nbr == data->nb_cmd)
// 	{
// 		// * handle redirect for the last child
// 	}

// }
