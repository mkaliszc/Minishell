/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:51:01 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/15 22:33:21 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	TODO : executing checklist (in child)
	* check where to redirect the entry and if we need, redirect the output
	* If we have an here_doc do it first
	! ulimit -n (if we open to much fd)
	? open file/pipe in the child dynamicly
	* find path to cmd and execve
	* do it for every pipe/cmd
	!! handle exit code !

	todo 2 : if we have only one cmd (no pipe)
	? redirecting then check if we have a builtins (for the parent)
	? if no then fork, redirect the child output and execve

	todo 3 : multiple cmd (1 or + pipes)
	! if we have a builtin like cd it don't work because it change the PWD and OLDPWD of the CHILD not the main
	? pipex but mine need some modifications (creation of pipes and structs etc)
	
	todo : redirection
	* redirect the STDIN to the last IN or HDC redirection (before the pipe)
	* if we don't have the permission on the infile the command isn't exec and the outfile isn't created if it doesn't exist
	! even if we don't have the perms we do every here_doc before exit/quit
	* finally we redirect the STDOUT to the last OUT or APP and create it if it doesn't exist
	! don't forget to unlink the tmp file of each heredoc before killing the child
	* if we have multiple here_doc we need to stock them then erase it with the next here_doc

	todo 3.1 : pipes
	* ulimit -n change the limit for both but they are separate for example :
	*		ulimit -n 25 set the limit to 25 so the main can open 25 fd and the child can open 25 fd too
	*		if the main open a fd (24 left) the child still have 25 left
	? so to handle it maybe we can create each pipe in the child before the redirection
	
	todo 4 : cmd 
	* check path for every command with access and our envp list
	! if no path execve wil "fail" and so we need to free evrything
	* execve
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
	while (data->lst_cmd)
	{
		if (data->lst_cmd->is_builtins == true && data->nb_cmd == 1)
		{
			which_builtins(data); // ! we need to handle the redirection before
		}
		else
		{
			// handle child etc
		}
		data->lst_cmd = data->lst_cmd->next;
	}
}
