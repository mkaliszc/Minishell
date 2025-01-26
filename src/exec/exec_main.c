/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:51:01 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/26 02:12:43 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	which_builtins(t_mini *data, t_lst_cmd *tmp)
{
	if (ft_strcmp("env", tmp->cmd[0]) == 0)
		handle_env(data->lst_env);
	else if (ft_strcmp("export", tmp->cmd[0]) == 0)
		handle_export(data->lst_cmd->cmd, &data->lst_env);
	else if (ft_strcmp("unset", tmp->cmd[0]) == 0)
		handle_unset(tmp->cmd, &data->lst_env);
	else if (ft_strcmp("cd", tmp->cmd[0]) == 0)
		handle_cd(tmp->cmd, data->lst_env);
	else if (ft_strcmp("pwd", tmp->cmd[0]) == 0)
		handle_pwd();
	else if (ft_strcmp("echo", tmp->cmd[0]) == 0)
		handle_echo(data->lst_cmd->cmd);
	else if (ft_strcmp("exit", tmp->cmd[0]) == 0)
		handle_exit(data);
}

void	handle_only_builtins(t_mini *tmp, t_data *data)
{
	handle_redir_no_pipe(tmp, data);
	if (tmp->exit_code == 0)
		which_builtins(tmp, tmp->lst_cmd);
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
	int i;

	i = -1;
	while (++i < mini->nb_cmd)
	{
		waitpid(mini->data->pid[i], &mini->exit_code, 0);
		if (WIFEXITED(mini->exit_code))
			mini->exit_code = WEXITSTATUS(mini->exit_code);
	}
}

void	executing_minishell(t_mini *mini)
{
	int		cur_cmd_nbr;
	t_lst_cmd	*tmp;

	if (mini->exit_code == 2)
		return ;
	cur_cmd_nbr = 0;
	mini->data = init_struct(mini);
	tmp = mini->lst_cmd;
	if (tmp->is_builtins == true && mini->nb_cmd == 1)
	{
		handle_only_builtins(mini, mini->data);
		return ;
	}
	else if (mini->nb_cmd == 1 && tmp->cmd[0] == NULL) // * fix temporaire (waiting for jbergos fix) replace 1 with 0
		return (handle_file(mini, mini->data));
	while (tmp)
	{
		handle_pipe(mini, mini->data, cur_cmd_nbr, tmp);
		cur_cmd_nbr++;
		tmp = tmp->next;
	}
	wait_for_child(mini);
}
