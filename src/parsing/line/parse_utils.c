/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 00:22:02 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/17 01:32:09 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	init_ft_brckt(int *i, int *cnt, char *a_brck)
{
	*i = 0;
	*cnt = 0;
	*a_brck = '\0';
}

void	while_s_quote(char *ln_cmd, int *index)
{
	++*index;
	while (ln_cmd[*index] != '\'' && ln_cmd[*index])
		++*index;
}

void	while_d_quote(char *ln_cmd, int *index)
{
	++*index;
	while (ln_cmd[*index] != '"' && ln_cmd[*index])
		++*index;
}

int	while_a_brck(char *ln_cmd, int *i, char *a_brck, int *cnt)
{
	++*cnt;
	*a_brck = ln_cmd[*i];
	++*i;
	while (ln_cmd[*i] == *a_brck)
	{
		++*i;
		++*cnt;
	}
	if (!ln_cmd[*i] || *cnt > 2)
		return (1);
	while (ln_cmd[*i] == ' ')
		++*i;
	if (!ln_cmd[*i])
		return (1);
	if (ln_cmd[*i] == '<' || ln_cmd[*i] == '>' || ln_cmd[*i] == '|')
		return (1);
	else
	{
		*cnt = 0;
		*a_brck = '\0';
	}
	return (0);
}
