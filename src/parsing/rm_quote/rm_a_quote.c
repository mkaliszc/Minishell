/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_a_quote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 03:43:35 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/28 04:01:42 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	length_n_quote(char *s)
{
	int	i;
	int len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '"' || s[i] == '\'')
		{
			++i;
			if (s[i - 1] == '"')
				while (s[i] && s[i] != '"')
					++i;
			else
				while (s[i] && s[i] != '\'')
					++i;
			len -= 2;
			++i;
		}
		else
			++i;
	}
	return (i + len);
}

char *rep_n_quote(char *s)
{
	char	*new;
	t_pain	pain;

	new = malloc(sizeof(char) * (length_n_quote(s) + 1));
	if (!new)
		return (NULL);
	pain.i = 0;
	pain.j = 0;
	while (s[pain.i])
	{
		if (s[pain.i] == '"' || s[pain.i] == '\'')
		{
			++pain.i;
			if (s[pain.i - 1] == '"')
				while(s[pain.i] && s[pain.i] != '"')
					new[pain.j++] = s[pain.i++];
			else
				while (s[pain.i] && s[pain.i] != '\'')
					new[pain.j++] = s[pain.i++];
			++pain.i;
		}
		else
			new[pain.j++] = s[pain.i++];
	}
	new[pain.j] = '\0';
	free(s);
	return (new);
}