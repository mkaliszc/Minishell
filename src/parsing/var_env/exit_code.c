/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 03:28:53 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/24 05:33:14 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	length_ec(int n)
{
	int	len;

	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	length_exit_code(int code, int *i, int *len)
{
	*i += 1;
	*len -= 1;
	*len += length_ec(code);
}

void	rep_exit_code(int code, char *new, t_pain *pain)
{
	char	*cd;
	int		k;

	pain->i += 2;
	cd = ft_itoa(code);
	if (!cd)
		return ;
	k = 0;
	while (cd[k])
	{
		new[pain->j] = cd[k];
		pain->j += 1;
		++k;
	}
	free(cd);
	return ;
}
