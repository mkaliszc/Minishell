/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:51:01 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/24 21:23:23 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	which_builtins(t_mini *data)
{
	if (ft_strcmp("env", data->lst_cmd->cmd[0]) == 0)
		handle_env(data->lst_env);
	else if (ft_strcmp("export", data->lst_cmd->cmd[0]) == 0)
		handle_export(data->lst_cmd->cmd, &data->lst_env);
	else if (ft_strcmp("unset", data->lst_cmd->cmd[0]) == 0)
		handle_unset(data->lst_cmd->cmd, &data->lst_env);
	else if (ft_strcmp("cd", data->lst_cmd->cmd[0]) == 0)
		handle_cd(data->lst_cmd->cmd, data->lst_env);
	else if (ft_strcmp("pwd", data->lst_cmd->cmd[0]) == 0)
		handle_pwd();
	else if (ft_strcmp("echo", data->lst_cmd->cmd[0]) == 0)
		handle_echo(data->lst_cmd->cmd);
	else if (ft_strcmp("exit", data->lst_cmd->cmd[0]) == 0)
		handle_exit(data);
}

void	handle_only_builtins(t_mini *tmp, t_data *data)
{
	handle_redir_no_pipe(tmp, data);
	if (tmp->exit_code == 0)
		which_builtins(tmp);
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

void	executing_minishell(t_mini *mini)
{
	t_data	*data;
	int		cur_cmd_nbr;
	t_mini	*tmp;

	cur_cmd_nbr = 0;
	data = init_struct(mini);
	tmp = mini;
	if (tmp->lst_cmd->is_builtins == true && tmp->nb_cmd == 1)
	{
		handle_only_builtins(tmp, data);
		return ;
	}
	else if (mini->nb_cmd == 1 && mini->lst_cmd->cmd[0] == NULL) // * fix temporaire (waiting for jbergos fix) replace 1 with 0
		return (handle_file(mini, data));
	while (tmp->lst_cmd)
	{
		handle_pipe(tmp, data, cur_cmd_nbr);
		cur_cmd_nbr++;
		tmp->lst_cmd = tmp->lst_cmd->next;
	}
	cur_cmd_nbr = -1;
	while (++cur_cmd_nbr < mini->nb_cmd)
		waitpid(data->pid[cur_cmd_nbr], &mini->exit_code, 0);
}
