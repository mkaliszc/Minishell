/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:03:55 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/26 17:26:33 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_pipe(t_mini *data, t_data *pipex, int cur_cmd, t_lst_cmd *tmp)
{
	if (pipe(pipex->pipe_fd + 2 * cur_cmd) == -1)
	{
		perror("pipe");
		free_minishell(data);
		exit(1);
	}
	pipex->pid[cur_cmd] = fork();
	if (pipex->pid[cur_cmd] == 0)
		handle_child(data, cur_cmd, pipex, tmp);
	close(pipex->pipe_fd[2 * cur_cmd + 1]);
	pipex->pipe_fd[2 * cur_cmd + 1] = -1;
	if (cur_cmd > 0)
	{
		close(pipex->pipe_fd[2 * (cur_cmd - 1)]);
		pipex->pipe_fd[2 * (cur_cmd - 1)] = -1;
	}
	if (cur_cmd == data->nb_cmd - 1)
		close(pipex->pipe_fd[2 * cur_cmd]);
}

void	handle_child(t_mini *data, int cmd_nbr, t_data	*pipex, t_lst_cmd *tmp)
{
	char	*path;

	if (data->nb_cmd == 1)
		handle_redir_no_pipe(data, pipex, tmp);
	else
		handle_redir(data, cmd_nbr, pipex, tmp);
	if (cmd_nbr > 0)
		close(pipex->pipe_fd[2 * (cmd_nbr - 1)]);
	close(pipex->pipe_fd[cmd_nbr * 2]);
	close(pipex->pipe_fd[cmd_nbr * 2 + 1]);
	if (tmp->is_builtins == true)
	{
		which_builtins(data, tmp);
		free_minishell(data);
		exit(data->exit_code);
	}
	path = validate_cmd_path(tmp->cmd, data->lst_env, data);
	if (execve(path, tmp->cmd, lst_to_char(data->lst_env)) == -1)
		perror_exit(data, "execve failed", 1);
}
