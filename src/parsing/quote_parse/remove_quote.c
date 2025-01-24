/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 06:30:33 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/24 04:16:34 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	length_without_quote(char *s)
{
	int	i;
	int	len;

	len = ft_strlen(s);
	printf("len with quote : %d\n", len);
	i = 0;
	while (s[i])
	{
		if (s[i] == '"')
		{
			while_d_quote(s, &i);
			len -= 2;
		}
		else if (s[i] == '\'')
		{
			while_s_quote(s, &i);
			len -= 2;
		}
		++i;
	}
	printf("len without quote : %d\n", len);
	return (len);
}

char	*get_key_length(char *s, int *i, int *cnt)
{
	int	start;
	int	end;

	++*i;
	--*cnt;
	start = *i;
	while (s[*i] && s[*i] != ' ' && s[*i] != '$' \
	&& s[*i] != '<' && s[*i] != '>' && s[*i] != '|' \
	&& s[*i] != '"' && s[*i] != '\'')
	{
		++*i;
		--*cnt;
	}
	end = *i;
	return (ft_substr(s, start, end - start));
}

void	length_var(char *s, t_env *env, int *i, int *cnt)
{
	char	*key;
	char	*var;

	key = get_key_length(s, i, cnt);
	var = get_env(env, key);
	if (var)
		*cnt += ft_strlen(var);
	if (key)
		free(key);
}

void	in_quote(char *s, t_mini *m_shell, int *i, int *cnt)
{
	++*i;
	if (s[*i - 1] == '"')
	{
		while (s[*i] && s[*i] != '"')
		{
			if (s[*i] == '$' && s[*i + 1] == '?')
				length_exit_code(m_shell->exit_code, i, cnt);
			else if (s[*i] == '$' && s[*i + 1] != ' ' && s[*i + 1] != '$' \
			&& s[*i + 1] != '<' && s[*i + 1] != '>' && s[*i + 1] != '|' \
			&& s[*i + 1] != '"' && s[*i + 1] != '\'' && s[*i + 1])
				length_var(s, m_shell->lst_env, i, cnt);
			else
				++*i;
		}
	}
	else
		while (s[*i] && s[*i] != '\'')
			++*i;
	*cnt -= 2;
	++*i;
}

int	length_o_var(char *s, t_mini *m_shell)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '"' || s[i] == '\'')
			in_quote(s, m_shell, &i, &len);
		else if (s[i] == '$' && s[i + 1] == '?')
			length_exit_code(m_shell->exit_code, &i, &len);
		else if (s[i] == '$' && s[i + 1] != ' ' && s[i + 1] != '$' \
		&& s[i + 1] != '<' && s[i + 1] != '>' && s[i + 1] != '|' \
		&& s[i + 1] != '"' && s[i + 1] != '\'' && s[i + 1])
			length_var(s, m_shell->lst_env, &i, &len);
		else
			++i;
	}
	return (i + len);
}
