/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 06:30:33 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/21 06:41:12 by jbergos          ###   ########.fr       */
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

// char	*remove_quote(char *s)
// {
// 	char	*sq;
// 	int		len;

// 	len = length_wihtout_quote(s);
// }