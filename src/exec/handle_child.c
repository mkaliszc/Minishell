/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/01/29 01:04:03 by jbergos          ###   ########.fr       */
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

void	sig_child(int sig)
{
	(void)sig;
	kill(0, SIGTERM);
}

void	handle_child(t_mini *data, int cmd_nbr, t_data	*pipex, t_lst_cmd *tmp)
{
	char	*path;
	// struct sigaction sa;
	// sa.sa_handler = sig_child;
	// sigemptyset(&sa.sa_mask);
	// sa.sa_flags = 0;
	// sigaction(SIGINT, &sa, NULL);

	if (data->nb_cmd == 1)
		handle_redir_no_pipe(data, pipex, tmp);
	else
		handle_redir(data, cmd_nbr, pipex, tmp);
	if (data->exit_code != 0)
	{
		free_minishell(data);
		exit(1);
	}
	if (cmd_nbr > 0)
		close(pipex->pipe_fd[2 * (cmd_nbr - 1)]);
	close(pipex->pipe_fd[cmd_nbr * 2]);
	close(pipex->pipe_fd[cmd_nbr * 2 + 1]);
	if (tmp->is_builtins == true)
	{
		which_builtins(data, tmp);
		free_minishell(data);
		exit(EXIT_SUCCESS);
	}
	if (!tmp->cmd)
	{
		free_minishell(data);
		exit(0);
	}
	path = validate_cmd_path(tmp->cmd, data->lst_env, data);
	char **lst_tochar = lst_to_char(data->lst_env);
	if (execve(path, tmp->cmd, lst_tochar) == -1)
	{
		free(path);
		ft_free_char_tab(lst_tochar);
		free_minishell(data);
		exit(0);
		// perror_exit(data, "execve failed", 1);
	}
}
