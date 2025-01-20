/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 03:04:45 by albillie          #+#    #+#             */
/*   Updated: 2024/12/06 05:11:29 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*copy;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
	{
		len = s_len - start;
	}
	copy = (char *) malloc ((len + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		copy[i] = s[start + i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
/*
int main()
{
	char *string = "Hello world";

	char *result = ft_substr(string, 5, 10);

	printf("%s\n", result);
}
*/
