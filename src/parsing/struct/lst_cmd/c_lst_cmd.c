/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_lst_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 01:54:34 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/20 01:12:12 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

t_lst_cmd	*create_cmd(char *one_cmd)
{
	t_lst_cmd	*cmd;

	cmd = malloc(sizeof(t_lst_cmd));
	if (!cmd)
		return (NULL);

	cmd->cmd = NULL;
	// cmd->order_file = // all in | out | hdc | app | ordered
	cmd->is_builtins = false;
	cmd->next = NULL;
}

void	lst_cmd_add_last(t_lst_cmd **lst_cmd, t_lst_cmd *cmd)
{
	t_lst_cmd	*tmp;

	if (!(*lst_cmd))
	{
		*lst_cmd = cmd;
		return ;
	}
	tmp = *lst_cmd;
	while (tmp)
	{
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
	tmp->next = cmd;
}

t_lst_cmd	*create_lst_cmd(char **cmd_split)
{
	t_lst_cmd	*lst_cmd;
	int			i;

	i = 0;
	lst_cmd = NULL;
	while (cmd_split[i])
	{
		lst_cmd_add_last(&lst_cmd, create_cmd(cmd_split[i]));
	}
	return (lst_cmd);
}

// t_lst_cmd	*create_cmd(char **split_ln_cmd)
// {
// 	t_lst_cmd	*cmd;

// 	cmd = malloc(sizeof(t_lst_cmd));
// 	if (!cmd)
// 		return (NULL);
// 	cmd->
// }
