/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:51:01 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/15 00:36:05 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	TODO : executing checklist
	? check parameter function
	* check where to redirect the entry and if we need, redirect the output
	* If we have an here_doc do it first
	! ulimit -n (if we open to much fd)
	* find path to cmd and execve
	* do it for every pipe
*/

void	which_builtins(t_mini *data)
{
	if (ft_strcmp("env", (*data->lst_cmd)->cmd[0]) == 0)
		handle_env(data->lst_env);
	if (ft_strcmp("export", (*data->lst_cmd)->cmd[0]) == 0)
		handle_export(data);
	if (ft_strcmp("unset", (*data->lst_cmd)->cmd[0]) == 0)
		handle_unset(data);
	if (ft_strcmp("cd", (*data->lst_cmd)->cmd[0]) == 0)
		handle_cd(data);
	if (ft_strcmp("pwd", (*data->lst_cmd)->cmd[0]) == 0)
		handle_pwd(data->lst_env);
	if (ft_strcmp("echo", (*data->lst_cmd)->cmd[0]) == 0)
		handle_echo(data);
	if (ft_strcmp("exit", (*data->lst_cmd)->cmd[0]) == 0)
		handle_exit(data);
}

void	executing_minishell(t_mini *data)
{
	t_order	*cur;
	int		status;
	char	*infile;

	cur = data->order;
	if ((*data->lst_cmd)->is_builtins == true && data->nb_cmd == 1)
		which_builtins(data);
	status = 0;
	while (cur)
	{
		if (status == 0 && cur->type == hdc)
		{
			infile = handle_heredoc();
			if (cur->next == NULL)
			{
				cur = data->order;
				status = 1;
			}		
		}
		else if (status == 1 && cur->type == in)
		{
			infile = handle_heredoc();
			if (cur->next == NULL)
			{
				cur = data->order;
				status = 1;
			}		
		}
	}	
}
