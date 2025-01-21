/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:54:16 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/21 02:29:05 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ! Create a function to close everything
// ! Handle all exit codes

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
			perror("redir in with single command");
			free_minishell(data);
			exit(1);
		}
	}
	else if (info->in_fd != 0)
	{
		if(dup2(info->in_fd, STDIN_FILENO) < 0)
		{
			perror("redir in");
			free_minishell(data);
			exit(1);
		}
	}
}

void	hande_redir_out(t_mini *data, int cmd_nbr, t_data *info)
{
	if (info->out_fd == 1 && cmd_nbr < data->nb_cmd)
	{
		if (dup2(info->pipe_fd[2 * cmd_nbr + 1], STDOUT_FILENO) < 0)
		{
			perror("out redir for last command");
			free_minishell(data);
			exit(EXIT_FAILURE);
		}
	}
	else if (info->out_fd != 1)
	{
		if (dup2(info->out_fd, STDOUT_FILENO) == -1)
		{
			perror("out redir");
			free_minishell(data);
			exit(EXIT_FAILURE);
		}
	}
}

void	handle_redir(t_mini *data, int cmd_nbr, t_data *info)
{
	if (cmd_nbr == 0)
	{
		if (info->in_fd != 0)
		{
			if (dup2(info->in_fd, STDIN_FILENO) == -1)
			{
				perror("redir in for the first command");
				free_mnishell(data);
				exit(EXIT_FAILURE);
			}
		}
		handle_redir_out(data, cmd_nbr, info);
	}
	else if (cmd_nbr == data->nb_cmd - 1)
	{
		handle_redir_in(data, cmd_nbr, info);
		if (info->out_fd != 0)
		{
			if (dup2(info->out_fd, STDOUT_FILENO))
			{
				perror("redir out for the last command");
				free_minishell(data);
				exit(EXIT_FAILURE);
			}
		}
	}
	else
	{
		handle_redir_in(data, cmd_nbr, info);
		handle_redir_out(data, cmd_nbr, info);
	}
}
