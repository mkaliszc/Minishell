/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 03:09:09 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/29 22:50:36 by jbergos          ###   ########.fr       */
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

char	**is_first_arg_empty(char **pptr)
{
	int		i;
	char	**rdm;
	int		count;

	i = 0;
	count = 0;
	while (pptr[i])
	{
		if (pptr[i][0] != '\0')
			count ++;
		++i;
	}
	if (count == 0)
		return (free_split(pptr), NULL);
	rdm = malloc(sizeof(char *) * (count + 1));
	i = 0;
	count = 0;
	while (pptr[i])
	{
		if (pptr[i][0] != '\0')
			rdm[count++] = ft_strdup(pptr[i]);
		++i;
	}
	rdm[count] = NULL;
	return (free_split(pptr), rdm);
}

char	**table_cmd(char *cmd, t_mini *m_shell)
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
			pptr[j++] = replace_o_var(get_args(cmd, &i), m_shell);
		if (!cmd[i])
			break ;
		++i;
	}
	pptr[j] = NULL;
	pptr = is_first_arg_empty(pptr);
	return (pptr);
}
