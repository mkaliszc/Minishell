/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:03:55 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/21 19:21:44 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_unused_pipes(int *pipe_fd, int cur_cmd)
{
	int	i;

	i = 0;
	while (pipe_fd[i] != -1 && i <= (cur_cmd - 1) * 2)
	{
		close(pipe_fd[i]);
		i++;
	}
}

void	handle_pipe(t_mini *data, t_data *info, int cur_cmd)
{
	if (pipe(info->pipe_fd + 2 * cur_cmd) == -1)
	{
		perror("pipe");
		free_minishell(data);
		exit(1);
	}
	info->pid[cur_cmd] = fork();
	if (info->pid[cur_cmd] == 0)
		handle_child(data, cur_cmd, info);
	close_unused_pipes(info->pipe_fd, cur_cmd);
}

void	handle_child(t_mini *data, int child_number, t_data	*info)
{
	char	*path;

	if (data->nb_cmd == 1)
		handle_redir_no_pipe(data, info);
	else
		handle_redir(data, child_number, info);
	if (data->lst_cmd->is_builtins == true)
	{
		which_builtins(data);
		free_minishell(data);
		exit(EXIT_SUCCESS);
	}
	path = validate_cmd_path(data->lst_cmd->cmd, data->lst_env, data);
	if (execve(path, data->lst_cmd->cmd, lst_to_char(data->lst_env)) == -1)
		perror_exit(data, "execve failed", 1);
}
