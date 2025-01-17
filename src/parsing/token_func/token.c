/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 03:09:09 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/17 06:20:30 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	nb_of_cmd(char *ln_cmd)
{
	int i;
	int	count;

	i = 0;
	count = 1;
	while (ln_cmd[i])
	{
		if (ln_cmd[i] == '"')
			while_d_quote(ln_cmd, &i);
		if (ln_cmd[i] == '\'')
			while_s_quote(ln_cmd, &i);
		if (ln_cmd[i] == '|')
			count++;
		++i;
	}
	return (count);
}

void	show_split(char **c_split)
{
	int	i;

	i = 0;
	while (c_split[i])
	{
		printf("split cmd : /%s/\n", c_split[i]);
		++i;
	}
}

void	free_split(char **c_split)
{
	int	i;

	i = 0;
	while (c_split[i])
	{
		free(c_split[i]);
		++i;
	}
	free(c_split);
}

void	split_cmd(char *ln_cmd)
{
	char **split_cmd;
	int		i;
	int		start;
	int		end;

	split_cmd = malloc(sizeof(char *) * (nb_of_cmd(ln_cmd) + 1));
	end = 0;
	start = 0;
	i = 0;
	while (ln_cmd[end])
	{
		if(ln_cmd[end] == '"')
			while_d_quote(ln_cmd, &end);
		if(ln_cmd[end] == '\'')
			while_s_quote(ln_cmd, &end);
		if(ln_cmd[end] == '|')
		{
			split_cmd[i++] = ft_substr(ln_cmd, start, end - start);
			start = end + 1;
		}
		if (!ln_cmd[end + 1])
			split_cmd[i++] = ft_substr(ln_cmd, start, end - start);
		++end;
	}
	split_cmd[i] = NULL;
}