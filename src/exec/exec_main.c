/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:51:01 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/29 00:00:59 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_only_file(t_mini *mini, t_lst_cmd *tmp)
{
	handle_file(mini, mini->data, tmp);
	if (mini->data->in_fd != 0)
		close(mini->data->in_fd);
	if (mini->data->out_fd != 1)
		close(mini->data->out_fd);
	return ;
}

void	handle_only_builtins(t_mini *data, t_lst_cmd *tmp, t_data *pipex)
{
	handle_file(data, pipex, tmp);
	if (data->exit_code != 0)
		return ;
	if (data->data->out_fd != 1)
		dup2(data->data->out_fd, STDOUT_FILENO);
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
	else if (ft_strcmp("exit", tmp->cmd[0]) == 0)
		handle_exit(data->lst_cmd->cmd, data);
}

t_data	*init_struct(t_mini *data)
{
	t_data	*res;

	res = malloc(sizeof(t_data));
	if (res == NULL)
		return (NULL);
	res->in_fd = 0;
	res->out_fd = 1;
	res->pid = malloc(sizeof(pid_t) * data->nb_cmd);
	if (res->pid == NULL)
	{
		free(res);
		return (NULL);
	}
	res->pipe_fd = malloc(sizeof(int) * data->nb_cmd * 2);
	ft_memset(res->pipe_fd, -1, data->nb_cmd * 2);
	return (res);
}

void	wait_for_child(t_mini *mini)
{
	int	i;
	int	status;

	i = -1;
	status = 0;
	while (++i < mini->nb_cmd)
	{
		waitpid(mini->data->pid[i], &status, 0);
		if (WIFEXITED(status))
			mini->exit_code = WEXITSTATUS(status);
	}
}

void	executing_minishell(t_mini *mini)
{
	int			cur_cmd_nbr;
	t_lst_cmd	*tmp;

	if (mini->exit_code == 2 || mini->lst_cmd == NULL || mini->lst_cmd->cmd == NULL)
		return ;
	cur_cmd_nbr = 0;
	mini->data = init_struct(mini);
	if (process_here_doc(mini))
		return (ft_putstr_fd("heredoc failure\n", 2));
	tmp = mini->lst_cmd;
	if (tmp->is_builtins == true && mini->nb_cmd == 1 && ft_strcmp("echo", tmp->cmd[0]) != 0)
	{
		handle_only_builtins(mini, mini->lst_cmd, mini->data);
		return ;
	}
	else if (mini->nb_cmd == 1 && tmp->cmd[0] == NULL)
		return (handle_only_file(mini, tmp));
	while (tmp)
	{
		handle_pipe(mini, mini->data, cur_cmd_nbr, tmp);
		cur_cmd_nbr++;
		tmp = tmp->next;
	}
	wait_for_child(mini);
}
