/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:51:01 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/15 03:37:48 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	TODO : executing checklist
	* check where to redirect the entry and if we need, redirect the output
	* If we have an here_doc do it first
	! ulimit -n (if we open to much fd)
	* find path to cmd and execve
	* do it for every pipe

	todo bis : if we have only one cmd (no pipe)
	? redirecting then check if we have a builtins (for the parent)
	? if no then fork, redirect the child output and execve

	todo : multiple pipes
	? pipex but need some modifications

*/
void	which_builtins(t_mini *data)
{
	if (ft_strcmp("env", *data->lst_cmd->cmd[0]) == 0)
		handle_env(data->lst_env);
	if (ft_strcmp("export", data->lst_cmd->cmd[0]) == 0)
		handle_export(data);
	if (ft_strcmp("unset", data->lst_cmd->cmd[0]) == 0)
		handle_unset(data);
	if (ft_strcmp("cd", data->lst_cmd->cmd[0]) == 0)
		handle_cd(data);
	if (ft_strcmp("pwd", data->lst_cmd->cmd[0]) == 0)
		handle_pwd(data->lst_env);
	if (ft_strcmp("echo", data->lst_cmd->cmd[0]) == 0)
		handle_echo(data);
	if (ft_strcmp("exit", data->lst_cmd->cmd[0]) == 0)
		handle_exit(data);
}

void	executing_minishell(t_mini *data)
{
	t_order_file	*cur;
	char			*infile;

	cur = data->lst_cmd->order_file;
	if (data->lst_cmd->is_builtins == true && data->nb_cmd == 1) // ! we need to do this after redirecting output and input
		which_builtins(data);
	while (cur)
	{
		if (cur->type == HDC)
			infile = handle_here_doc(cur->file);
		else if (cur->type == IN)
			infile = cur->file;
		cur = cur->next;
	}
}
