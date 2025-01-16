/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 02:24:19 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/16 01:55:47 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/jojo.h"

int	empty_line(char *ln_cmd)
{
	int	i;

	i = 0;
	while (ln_cmd[i])
	{
		if (ln_cmd[i] != ' ')
			return (0);
		++i;
	}
	return (1);
}

char	*find_var(char *ln_cmd)
{
	char	*find;
	int		start;
	int		end;

	start = 0;
	while (ln_cmd[start] && ln_cmd[start] != '$')
		++start;
	if (!ln_cmd[start])
		return (NULL);
	end = start;
	while (ln_cmd[end] && ln_cmd[end] != ' ')
		++end;
	find = ft_substr(ln_cmd, start + 1, end - start);
	return (find);
}

void	find_n_replace_var(t_mini *m_shell, char *ln_cmd)
{
	char *find;

	find = find_var(ln_cmd);
	if (find)
	{
		printf("%s\n", find);
		show_one_lst_env(m_shell->lst_env, find);
		free(find);
	}
}
