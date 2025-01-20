/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 01:46:45 by albillie          #+#    #+#             */
/*   Updated: 2024/12/06 05:11:30 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == (char) c)
		{
			return ((char *) s + i);
		}
		i--;
	}
	if (s[i] == (char) c)
	{
		return ((char *) s + i);
	}
	return (NULL);
}
/* int	main()
{
	char *s = "Hello World!";
	char ch = 'o';
	char *result = ft_strrchr(s, ch);

	printf("%s\n", result);
} */
