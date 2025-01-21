/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 02:24:19 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/21 04:33:38 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

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

int	is_border_pipe(char *ln_cmd)
{
	int		i;
	char	st;
	char	end;

	i = 0;
	st = '\0';
	while (ln_cmd[i])
	{
		if (ln_cmd[i] != ' ')
		{
			end = ln_cmd[i];
			if (!st)
				st = ln_cmd[i];
		}
		++i;
	}
	if (st == '|' || end == '|')
		return (ft_error('|'), 1);
	return (0);
}

int	is_quote_closed(char *ln_cmd)
{
	int		i;
	char	quote;

	quote = '\0';
	i = 0;
	while (ln_cmd[i])
	{
		if (ln_cmd[i] == quote)
		{
			quote = '\0';
			++i;
		}
		if (!ln_cmd[i])
			break ;
		if ((ln_cmd[i] == '"' || ln_cmd[i] == '\'') && !quote)
			quote = ln_cmd[i];
		++i;
	}
	if (quote)
		return (ft_error(quote), 1);
	return (0);
}

int	is_good_angle_bracket(char *ln_cmd)
{
	int		i;
	int		count;
	char	a_bracket;

	init_ft_brckt(&i, &count, &a_bracket);
	while (ln_cmd[i])
	{
		if (ln_cmd[i] == '"')
			while_d_quote(ln_cmd, &i);
		if (ln_cmd[i] == '\'')
			while_s_quote(ln_cmd, &i);
		if (!a_bracket && (ln_cmd[i] == '<' || ln_cmd[i] == '>'))
		{
			if (while_a_brck(ln_cmd, &i, &a_bracket, &count))
				break ;
		}
		else
			++i;
		if (!ln_cmd[i])
			break ;
	}
	if (a_bracket)
		return (ft_error(a_bracket), 1);
	return (0);
}

int	is_dbl_pipe(char *ln_cmd)
{
	int	i;

	i = 0;
	while (ln_cmd[i])
	{
		if (ln_cmd[i] == '"')
			while_d_quote(ln_cmd, &i);
		if (ln_cmd[i] == '\'')
			while_s_quote(ln_cmd, &i);
		if (ln_cmd[i] == '|')
		{
			++i;
			while (ln_cmd[i] == ' ')
				++i;
			if (ln_cmd[i] == '|')
				return (ft_error('|'), 1);
		}
		else
			++i;
	}
	return (0);
}
