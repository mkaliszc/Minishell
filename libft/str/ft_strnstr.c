/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 06:04:10 by albillie          #+#    #+#             */
/*   Updated: 2024/12/06 05:11:30 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	i2;

	if (!little[0])
		return ((char *) big);
	if ((!big || !little) && !len)
		return (NULL);
	i = 0;
	while (big[i] && i < len)
	{
		i2 = 0;
		while (big[i + i2] && little[i2] && (i + i2)
			< len && big[i + i2] == little[i2])
		{
			i2++;
		}
		if (!little[i2])
			return ((char *) &big[i]);
		i++;
	}
	return (NULL);
}

/* int main()
{
	char *big = "hello";
	char *little = "\0";

	printf("%s\n", ft_strnstr(big, little, 4));
} */
