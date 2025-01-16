/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_lst_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 01:54:34 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/15 23:58:42 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/jojo.h"

t_lst_cmd	*create_lst_cmd(char *ln_cmd)
{
	t_lst_cmd	*lst_cmd;
	char	**split_ln_cmd;

	lst_cmd = NULL;
	split_ln_cmd = ft_split(ln_cmd, ' ');
}

// t_lst_cmd	*create_cmd(char **split_ln_cmd)
// {
// 	t_lst_cmd	*cmd;

// 	cmd = malloc(sizeof(t_lst_cmd));
// 	if (!cmd)
// 		return (NULL);
// 	cmd->
// }