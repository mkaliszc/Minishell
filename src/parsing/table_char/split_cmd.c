/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 04:29:57 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/29 08:56:47 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	nb_of_cmd(char *ln_cmd)
{
	int	i;
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
	if (!c_split)
	{
		printf("no cmd \n");
		return ;
	}
	if (!c_split[0])
	{
		printf("no cmd \n");
		return ;
	}
	while (c_split[i])
	{
		if (i == 0)
			printf("cmd : |%s|\n", c_split[i]);
		else
			printf("args number |%d| : |%s|\n", i, c_split[i]);
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

void	init_split_cmd(int *i, int *end, int *start)
{
	*i = 0;
	*start = 0;
	*end = 0;
}

char	**split_cmd(char *ln_cmd)
{
	char	**split_cmd;
	int		i;
	int		start;
	int		end;

	split_cmd = malloc(sizeof(char *) * (nb_of_cmd(ln_cmd) + 1));
	init_split_cmd(&i, &end, &start);
	while (ln_cmd[end])
	{
		if (ln_cmd[end] == '"')
			while_d_quote(ln_cmd, &end);
		if (ln_cmd[end] == '\'')
			while_s_quote(ln_cmd, &end);
		if (ln_cmd[end] == '|')
		{
			split_cmd[i++] = ft_substr(ln_cmd, start, end - start);
			start = end + 1;
		}
		if (!ln_cmd[end + 1])
			split_cmd[i++] = ft_substr(ln_cmd, start, end + 1 - start);
		++end;
	}
	split_cmd[i] = NULL;
	return (split_cmd);
}
