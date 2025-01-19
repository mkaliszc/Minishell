/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_modify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 00:20:40 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/17 01:32:22 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

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
	char	*find;

	find = find_var(ln_cmd);
	if (find)
	{
		show_one_lst_env(m_shell->lst_env, find);
		free(find);
	}
}
