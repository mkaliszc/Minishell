/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:10:39 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/29 01:15:13 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	which_builtins(t_mini *data, t_lst_cmd *tmp)
{
	if (ft_strcmp("env", tmp->cmd[0]) == 0)
		handle_env(data->lst_env);
	else if (ft_strcmp("export", tmp->cmd[0]) == 0)
		handle_export(data->lst_cmd->cmd, &data);
	else if (ft_strcmp("unset", tmp->cmd[0]) == 0)
		handle_unset(tmp->cmd, &data->lst_env);
	else if (ft_strcmp("cd", tmp->cmd[0]) == 0)
		handle_cd(tmp->cmd, data);
	else if (ft_strcmp("pwd", tmp->cmd[0]) == 0)
		handle_pwd();
	else if (ft_strcmp("echo", tmp->cmd[0]) == 0)
		handle_echo(tmp->cmd);
	else if (ft_strcmp("exit", tmp->cmd[0]) == 0)
		handle_exit(tmp->cmd, data);
}

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

void	process_redir(t_mini *data, int cmd_nbr, t_data *pipex, t_lst_cmd *tmp)
{
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
}

void	handle_child(t_mini *data, int cmd_nbr, t_data	*pipex, t_lst_cmd *tmp)
{
	char	*path;
	char	**lst_tochar;
	// struct sigaction sa;
	// sa.sa_handler = sig_child;
	// sigemptyset(&sa.sa_mask);
	// sa.sa_flags = 0;
	// sigaction(SIGINT, &sa, NULL);

	process_redir(data, cmd_nbr, pipex, tmp);
	if (tmp->is_builtins == true)
	{
		which_builtins(data, tmp);
		free_minishell(data);
		exit(EXIT_SUCCESS);
	}
	if (!tmp->cmd)
		(free_minishell(data), exit(0));
	path = validate_cmd_path(tmp->cmd, data->lst_env, data);
	lst_tochar = lst_to_char(data->lst_env);
	if (execve(path, tmp->cmd, lst_tochar) == -1)
	{
		free(path);
		ft_free_char_tab(lst_tochar);
		free_minishell(data);
		exit(0);
		// perror_exit(data, "execve failed", 1);
	}
}
