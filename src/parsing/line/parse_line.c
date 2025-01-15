/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 02:24:19 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/15 03:39:28 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/jojo.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		++i;
	}
	return (s1[i] - s2[i]);
}

int	is_wrong_line(char *ln_cmd)
{
	t_tokens	token;
	int			i;

/*
* parcourir la chaine de caractere
! ne pas la split par les espaces car le "|" passes a la prochaine fonction meme si il est attache	
*/
}