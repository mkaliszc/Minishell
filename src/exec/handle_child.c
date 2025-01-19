/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:03:55 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/19 17:43:54 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	todo : handle pipe
	* we need conditions to redirect to the pipes for the first, last and for every child
	? if first child we only need to redirect the output in normal time (pipe and no redir out)
	? if last child we only need to redirect the input to the pipe
*/

void	close_unused_pipes(int *pipe_fd, int cur_cmd)
{
	int	i;

	while(pipe_fd[i] != -1 && i < (cur_cmd - 1) * 2)
	{
		close(pipe_fd[i]);
		i++;
	}
}

void	handle_pipe(t_mini *data, t_data *info, int cur_cmd)
{
	if (pipe(info->pipe_fd[cur_cmd * 2]) == -1)
	{
		perror("pipe creation failed");
		free_minishell(data);
		exit(1); // ! Exit with valid exit code right here
	}
	info->pid[cur_cmd] = fork();
	if (info->pid[cur_cmd] == 0)
		handle_child(data, cur_cmd, info);
	close_unused_pipes(info->pipe_fd, cur_cmd);
}

void	handle_child(t_mini *data, int child_number, t_data	*info)
{
	char	*path;

	handle_redir(data, child_number, info);
	if (data->lst_cmd->is_builtins == true)
		which_builtins(data); // ? exit
		which_builtins(data); // ? free_all + exit
	path = validate_cmd(data->lst_cmd, data->lst_env);
	if (execve(path, data->lst_cmd->cmd, lst_to_char(data->lst_env)) == -1)
	{
		free_minishell(data);
		exit(1) // ! Maybe add the valid exit code out here
	}
}
