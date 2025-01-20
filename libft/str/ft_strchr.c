/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:53:14 by albillie          #+#    #+#             */
/*   Updated: 2024/12/06 05:11:30 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	cc;

	cc = (char) c;
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
/*
int	main()
{
	char *string = "kaveo";
	char c = '\0';
	char *result = ft_strchr(string, c);

	printf("%s\n", result);
}
*/
