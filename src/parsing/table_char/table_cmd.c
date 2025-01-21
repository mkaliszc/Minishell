/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 03:09:09 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/21 04:43:04 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	while_a_brckt(char *cmd, int *i)
{
	while ((cmd[*i] == '<' || cmd[*i] == '>') && cmd[*i])
		++*i;
	while (cmd[*i] == ' ' && cmd[*i])
		++*i;
	while (cmd[*i] && cmd[*i] != ' ')
	{
		if (cmd[*i] == '"')
			while_d_quote(cmd, i);
		else if (cmd[*i] == '\'')
			while_s_quote(cmd, i);
		++*i;
	}
}

int	count_cmd_n_args(char *cmd)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (cmd[i])
	{
		if (cmd[i] == ' ')
			++i;
		else if (cmd[i] == '<' || cmd[i] == '>')
			while_a_brckt(cmd, &i);
		else
		{
			while (cmd[i] && (cmd[i] != ' ' && cmd[i] != '<' && cmd[i] != '>'))
			{
				if (cmd[i] == '"')
					while_d_quote(cmd, &i);
				else if (cmd[i] == '\'')
					while_s_quote(cmd, &i);
				++i;
			}
			++count;
		}
	}
	return (count);
}

char	*get_args(char *cmd, int *i)
{
	int	start;
	int	end;

	start = *i;
	while (cmd[*i] && (cmd[*i] != ' ' && cmd[*i] != '<' && cmd[*i] != '>'))
	{
		if (cmd[*i] == '"')
			while_d_quote(cmd, i);
		else if (cmd[*i] == '\'')
			while_s_quote(cmd, i);
		++*i;
	}
	end = *i;
	return (ft_substr(cmd, start, end - start));
}

char	**table_cmd(char *cmd)
{
	char	**pptr;
	int		len;
	int		i;
	int		j;

	len = count_cmd_n_args(cmd);
	pptr = malloc(sizeof(char *) * (len + 1));
	i = 0;
	j = 0;
	while (cmd[i] && j < len)
	{
		if (cmd[i] == ' ')
			;
		else if (cmd[i] == '<' || cmd[i] == '>')
			while_a_brckt(cmd, &i);
		else
			pptr[j++] = get_args(cmd, &i);
		if (!cmd[i])
			break ;
		++i;
	}
	pptr[j] = NULL;
	return (pptr);
}
