/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:51:01 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/20 04:30:31 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	TODO : executing checklist (in child)
	* check where to redirect the entry and if we need, redirect the output
	! ulimit -n (if we open to much fd)
	? open file/pipe in the child dynamicly
	!! handle exit code !

	todo 2 : if we have only one cmd (no pipe)
	* redirecting then check if we have a builtins (for the parent)
	? if not a builtins then fork, redirect the child output/entry and execve

	todo 3 : multiple cmd (1 or + pipes)
	? pipex need to be executed from left to right (changing one while when creating my lst of cmd)

	todo : redirection
	* if we don't have the permission on the infile the command isn't exec and the outfile isn't created if it doesn't exist
	! even if we don't have the perms we do every here_doc before exit/quit
	! don't forget to unlink the tmp file of heredoc
*/

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
		return(NULL);
	}
	res->pipe_fd = malloc(sizeof(int) * data->nb_cmd * 2);
	ft_memset(res->pipe_fd, -1, data->nb_cmd * 2);
	return (res);

}

void	executing_minishell(t_mini *data)
{
	t_data	*info;
	int		cur_cmd_nbr;

	cur_cmd_nbr = 0;
	info = init_struct(data);
	while (data->lst_cmd)
	{
		if (data->lst_cmd->is_builtins == true && data->nb_cmd == 1)
		{
			if (handle_redir_no_pipe(data) != 0)
			{
				// ! error code handling without quitting the prog
			}
			else
				which_builtins(data);
		}
		else
			handle_pipe(data, info, cur_cmd_nbr);
		cur_cmd_nbr++;
		data->lst_cmd = data->lst_cmd->next; // ? free previous node or do a free all at the end ?
	}
}
