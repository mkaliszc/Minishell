/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:51:01 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/18 18:22:21 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	TODO : executing checklist (in child)
	* check where to redirect the entry and if we need, redirect the output
	* If we have an here_doc do it first
	* if we have multiple here_doc we need to stock them then erase it with the next here_doc
	! ulimit -n (if we open to much fd)
	? open file/pipe in the child dynamicly
	* find path to cmd and execve
	* do it for every pipe/cmd
	!! handle exit code !

	todo 2 : if we have only one cmd (no pipe)
	* redirecting then check if we have a builtins (for the parent)
	? if not a builtins then fork, redirect the child output/entry and execve

	todo 3 : multiple cmd (1 or + pipes)
	! if we have a builtin like cd it don't work because it change the PWD and OLDPWD of the CHILD not the main
	? pipex but mine need some modifications (creation of pipes and structs etc)
	? pipex need to be executed from left to right (changing one while when creating my lst of cmd)
	
	todo : redirection
	* redirect the STDIN to the last IN or HDC redirection (before the pipe)
	* if we don't have the permission on the infile the command isn't exec and the outfile isn't created if it doesn't exist
	! even if we don't have the perms we do every here_doc before exit/quit
	* finally we redirect the STDOUT to the last OUT or APP and create it if it doesn't exist
	! don't forget to unlink the tmp file of heredoc
	? redirection with pipes ? boolean for handle_out to see if we find a out or not

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
void	which_builtins(t_mini *data) // ! need updates here with what is requires for each functions
{
	if (ft_strcmp("env", *data->lst_cmd->cmd[0]) == 0)
		handle_env(data->lst_env);
	else if (ft_strcmp("export", data->lst_cmd->cmd[0]) == 0)
		handle_export(data);
	else if (ft_strcmp("unset", data->lst_cmd->cmd[0]) == 0)
		handle_unset(data);
	else if (ft_strcmp("cd", data->lst_cmd->cmd[0]) == 0)
		handle_cd(data);
	else if (ft_strcmp("pwd", data->lst_cmd->cmd[0]) == 0)
		handle_pwd(data->lst_env);
	else if (ft_strcmp("echo", data->lst_cmd->cmd[0]) == 0)
		handle_echo(data);
	else if (ft_strcmp("exit", data->lst_cmd->cmd[0]) == 0)
		handle_exit(data);
}

t_data	*init_struct(t_mini *data)
{
	t_data	*res;

	res = malloc(sizeof(t_data));
	if (res == NULL)
		return(NULL);
	res->in_fd = -1;
	res->out_fd = -1;
	res->pid = malloc(sizeof(pid_t) * data->nb_cmd);
	if (res->pid == NULL)
	{
		free(res);
		return(NULL);
	}
	return (res);
	
}

void	executing_minishell(t_mini *data)
{
	t_data	*info;
	int	cur_cmd_nbr; // ? to handle first cmd and last cmd

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
			handle_pipes(data, info);
		cur_cmd_nbr++;
		data->lst_cmd = data->lst_cmd->next; // ? free previous node or do a free all at the end ?
	}
}
