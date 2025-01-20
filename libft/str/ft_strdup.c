/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 02:08:31 by albillie          #+#    #+#             */
/*   Updated: 2024/12/06 05:11:30 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_str;
	int		s_len;

	s_len = ft_strlen(s) + 1;
	new_str = malloc(s_len);
	if (!new_str)
	{
		return (NULL);
	}
	ft_strlcpy(new_str, s, s_len);
	return (new_str);
}
/*
int main()
{
	char string[] = "TEST";

	char *result = ft_strdup(string);

	printf("%s\n", result);
}
*/
