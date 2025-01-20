/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:54:16 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/20 22:47:00 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
void	handle_redir_in(t_mini *data, int cmd_nbr, t_data *info)
{
	if(info->in_fd == 0 && cmd_nbr != 0)
	{
		if (dup2(info->pipe_fd[2 * cmd_nbr - 1], STDIN_FILENO) < 0)
		{
			// ! perror etc
		}
	}
	else if (info->in_fd != 0)
	{
		if(dup2(info->in_fd, STDIN_FILENO) < 0)
		{
			// ! perror etc
		}
	}
}

void	hande_redir_out(t_mini *data, int cmd_nbr, t_data *info)
{
	if (info->out_fd == 1 && cmd_nbr < data->nb_cmd)
	{
		if (dup2(info->pipe_fd[2 * cmd_nbr + 1], STDOUT_FILENO) < 0)
		{
			// ! perror etc
		}
	}
	else if (info->out_fd != 1)
	{
		if (dup2(info->out_fd, STDOUT_FILENO))
		{
			// ! perror etc
		}
	}
}

void	handle_redir(t_mini *data, int cmd_nbr, t_data *info)
{
	if (cmd_nbr == 0)
	{
		if (info->in_fd != 0)
		{
			if (dup2(info->in_fd, STDIN_FILENO)); // ! supress ";" when the code is comnplete
				// ? perror etc
		}
		handle_redir_out(data, cmd_nbr, info);
	}
	else if (cmd_nbr == data->nb_cmd - 1)
	{
		handle_redir_in(data, cmd_nbr, info);
		if (info->out_fd != 0)
		{
			if (dup2(info->out_fd, STDOUT_FILENO)); // ! supress ";" when the code is comnplete
				// ? perror etc
		}
	}
	else
	{
		handle_redir_in(data, cmd_nbr, info);
		handle_redir_out(data, cmd_nbr, info);
	}
}
