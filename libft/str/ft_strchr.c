/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:53:14 by albillie          #+#    #+#             */
/*   Updated: 2025/01/28 01:05:21 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	cc;

	cc = (char) c;
	if (!s)
		return (NULL);
	if (!cc)
	{
		return ((char *) s + ft_strlen(s));
	}
	while (*s)
	{
		if (*s == cc)
		{
			return ((char *) s);
		}
		s++;
	}
	return (NULL);
}
