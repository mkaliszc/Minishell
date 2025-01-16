/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 01:56:37 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/16 03:57:57 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_space(char *ln_cmd)
{
	int	i;

	i = 0;
	while(ln_cmd[i] && ln_cmd[i] == ' ')
		++i;
	return (i);
}

int	is_pipe(char *ln_cmd, int *count)
{
	int	i;

	i = 0;
	while(ln_cmd[i] && ln_cmd == '|')
		++i;
	if (i)
		++count;
	return (i);
}

int is_d_quote(char *ln_cmd, int *count)
{
	int	i;

	i = 0;
	if (ln_cmd[i] != '"')
		return (i);
	else
	while(ln_cmd[i])
	{
		if (ln_cmd[i] == '"')
		{
			++i;
			while(ln_cmd[i] != '"')
				++i;
		}
		if (ln_cmd[i] == '\'')
		{
			++i;
			while(ln_cmd[i] != '\'')
					++i;
		}

	}
}

int	count_cmd(char *ln_cmd)
{
	int	i;
	int	count;

	count = 0;
	while (ln_cmd[i])
	{
		i += is_space(ln_cmd + i);
		i += is_pipe(ln_cmd + i, &count);
		i += is_d_quote(ln_cmd + i, &count);
		i += is_s_quote(ln_cmd + i, &count);
		i += is_in_chev(ln_cmd + i, &count);
		i += is_out_chev(ln_cmd + i, &count);
		++i;
	}
}

char	**split_line(char *ln_cmd)
{
	char	**cmd_splited;
	int		len;

	len = count_cmd(ln_cmd);
	cmd_splited = malloc(sizeof(char *) * (len + 1));
}
