/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rep_q_n_v.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 02:30:39 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/24 05:12:14 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*get_key(char *s, int *i)
{
	int	start;
	int	end;

	++*i;
	start = *i;
	while (s[*i] && s[*i] != ' ' && s[*i] != '$' \
	&& s[*i] != '<' && s[*i] != '>' && s[*i] != '|' \
	&& s[*i] != '"' && s[*i] != '\'')
		++*i;
	end = *i;
	return (ft_substr(s, start, end - start));
}

void	rv(char *key, t_env *env, int *j, char *new)
{
	int		k;
	char	*var;

	var = get_env(env, key);
	if (var)
	{
		k = 0;
		while (var[k])
		{
			new[*j] = var[k];
			++*j;
			++k;
		}
	}
	if (key)
		free(key);
}

int	if_for_var(char *s, int i)
{
	if (s[i] == '$' && s[i + 1] != ' ' && s[i + 1] != '$' \
	&& s[i + 1] != '<' && s[i + 1] != '>' && s[i + 1] != '|' \
	&& s[i + 1] != '"' && s[i + 1] != '\'' && s[i + 1])
		return (1);
	return (0);
}

void	wololo(t_pain *pain, t_mini *m_shell, char *s, char *new)
{
	++pain->i;
	if (s[pain->i - 1] == '"')
	{
		while (s[pain->i] && s[pain->i] != '"')
		{
			if (s[pain->i] == '$' && s[pain->i + 1] == '?')
				rep_exit_code(m_shell->exit_code, new, pain);
			else if (if_for_var(s, pain->i))
				rv(get_key(s, &pain->i), m_shell->lst_env, &pain->j, new);
			else
				new[pain->j++] = s[pain->i++];
		}
	}
	else
		while (s[pain->i] && s[pain->i] != '\'')
			new[pain->j++] = s[pain->i++];
	++pain->i;
}

char	*replace_o_var(char *s, t_mini *m_shell)
{
	char	*new;
	t_pain	pain;

	new = malloc(sizeof(char) * (length_o_var(s, m_shell) + 1));
	if (!new)
		return (NULL);
	pain.i = 0;
	pain.j = 0;
	while (s[pain.i])
	{
		if (s[pain.i] == '"' || s[pain.i] == '\'')
			wololo(&pain, m_shell, s, new);
		else if (s[pain.i] == '$' && s[pain.i + 1] == '?')
			rep_exit_code(m_shell->exit_code, new, &pain);
		else if (if_for_var(s, pain.i))
			rv(get_key(s, &pain.i), m_shell->lst_env, &pain.j, new);
		else
			new[pain.j++] = s[pain.i++];
	}
	new[pain.j] = '\0';
	free(s);
	return (new);
}
