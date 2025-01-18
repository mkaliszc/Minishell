/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:03:55 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/17 23:29:02 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* 
	todo : handle pipe
	* we need conditions to redirect to the pipes for the first, last and for every child
	? if first child we only need to redirect the output in normal time (pipe and no redir out)
	? if last child we only need to redirect the input to the pipe
*/

void	handle_pipe(t_mini *data, t_data *info)
{
	// * fork + create pipe etc 
}

void	handle_child(t_mini *data, int child_number)
{
	char	*path;
	handle_redir(data, child_number);
	if (data->lst_cmd->is_builtins == true)
		which_builtins(data); // ? exit 
	path = validate_cmd(data->lst_cmd, data->lst_env);
	if (execve(path, data->lst_cmd->cmd, lst_to_char(data->lst_env)) < 0);
}
