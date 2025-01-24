/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:03:55 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/24 21:08:32 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_pipe(t_mini *data, t_data *pipex, int cur_cmd)
{
	if (pipe(pipex->pipe_fd + 2 * cur_cmd) == -1)
	{
		perror("pipe");
		free_minishell(data);
		exit(1);
	}
	pipex->pid[cur_cmd] = fork();
	if (pipex->pid[cur_cmd] == 0)
		handle_child(data, cur_cmd, pipex);
	close(pipex->pipe_fd[2 * cur_cmd + 1]);
	pipex->pipe_fd[2 * cur_cmd + 1] = -1;
	if (cur_cmd > 0)
	{
		close(pipex->pipe_fd[2 * (cur_cmd - 1)]);
		pipex->pipe_fd[2 * (cur_cmd - 1)] = -1;
	}
	else if (cur_cmd == 0 && data->nb_cmd == 1)
		close(pipex->pipe_fd[2 * cur_cmd]);
}

void	handle_child(t_mini *data, int child_number, t_data	*pipex)
{
	char	*path;

	if (data->nb_cmd == 1)
		handle_redir_no_pipe(data, pipex);
	else
		handle_redir(data, child_number, pipex);
	if (data->lst_cmd->is_builtins == true)
	{
		which_builtins(data);
		free_minishell(data);
		exit(EXIT_SUCCESS);
	}
	if (child_number > 0)
		close(pipex->pipe_fd[2 * (child_number - 1)]);
	close(pipex->pipe_fd[child_number * 2]);
	close(pipex->pipe_fd[child_number * 2 + 1]);
	path = validate_cmd_path(data->lst_cmd->cmd, data->lst_env, data);
	if (execve(path, data->lst_cmd->cmd, lst_to_char(data->lst_env)) == -1)
		perror_exit(data, "execve failed", 1);
}
