/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_lst_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 01:54:34 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/19 01:42:10 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

t_lst_cmd	*create_cmd(char *one_cmd)
{
	t_lst_cmd	*cmd;

	cmd = malloc(sizeof(t_lst_cmd));
	if (!cmd)
		return (NULL);

	cmd->cmd = // cmmd and args
	cmd->order_file = // all in | out | hdc | app | ordered
	cmd->hdc = // order hdc
	cmd->is_builtins = // is cmd is builtins
	cmd->next = NULL;
}

t_lst_cmd	*create_lst_cmd(char *ln_cmd)
{
	t_lst_cmd	*lst_cmd;
	char		**split_ln_cmd;

	lst_cmd = NULL;
}

// t_lst_cmd	*create_cmd(char **split_ln_cmd)
// {
// 	t_lst_cmd	*cmd;

// 	cmd = malloc(sizeof(t_lst_cmd));
// 	if (!cmd)
// 		return (NULL);
// 	cmd->
// }
