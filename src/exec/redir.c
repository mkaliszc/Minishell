/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:54:16 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/29 02:48:21 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_redir_no_pipe(t_mini *data, t_data *info, t_lst_cmd *tmp)
{
	handle_file(data, info, tmp);
	if (info->in_fd == -1 || info->out_fd == -1 || data->exit_code == 126)
		return (perror("error while opening a file"));
	if (info->in_fd != 0 && dup2(info->in_fd, STDIN_FILENO) < 0)
		return (perror("error while redirecting the entry"));
	if (info->in_fd != 0)
		close(info->in_fd);
	if (info->out_fd != 1 && dup2(info->out_fd, STDOUT_FILENO) < 0)
		return (perror("error while redirecting the output"));
	if (info->out_fd != 1)
		close(info->out_fd);
	return ;
}

void	handle_redir_in(t_mini *data, int cmd_nbr, t_data *info)
{
	if (info->in_fd == 0 && cmd_nbr != 0)
	{
		if (dup2(info->pipe_fd[2 * cmd_nbr - 2], STDIN_FILENO) == -1)
			perror_exit(data, "redir in with single command", 1);
	}
	else if (info->in_fd != 0)
	{
		if (dup2(info->in_fd, STDIN_FILENO) == -1)
			perror_exit(data, "redir in", 1);
	}
}

void	handle_redir_out(t_mini *data, int cmd_nbr, t_data *info)
{
	if (info->out_fd == 1 && cmd_nbr < data->nb_cmd)
	{
		if (dup2(info->pipe_fd[2 * cmd_nbr + 1], STDOUT_FILENO) == -1)
			perror_exit(data, "out redir for last command", 1);
	}
	else if (info->out_fd != 1)
	{
		if (dup2(info->out_fd, STDOUT_FILENO) == -1)
			perror_exit(data, "out redir", 1);
	}
}

void	handle_first_child(t_mini *data, int cmd_nbr, t_data *info)
{
	if (info->in_fd != 0)
	{
		if (dup2(info->in_fd, STDIN_FILENO) == -1)
			perror_exit(data, "redir in for the first command", 1);
	}
	handle_redir_out(data, cmd_nbr, info);
}

void	handle_redir(t_mini *data, int cmd_nbr, t_data *info, t_lst_cmd *tmp)
{
	handle_file(data, info, tmp);
	if (data->exit_code == 126)
		return ;
	if (cmd_nbr == 0)
		handle_first_child(data, cmd_nbr, info);
	else if (cmd_nbr == data->nb_cmd - 1)
	{
		handle_redir_in(data, cmd_nbr, info);
		if (info->out_fd != 1)
		{
			if (dup2(info->out_fd, STDOUT_FILENO) == -1)
				perror_exit(data, "redir out for the last command", 1);
		}
	}
	else
	{
		handle_redir_in(data, cmd_nbr, info);
		handle_redir_out(data, cmd_nbr, info);
	}
	if (info->in_fd != 0)
		close(info->in_fd);
	if (info->out_fd != 1)
		close(info->out_fd);
}
