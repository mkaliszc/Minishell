/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 01:59:11 by albillie          #+#    #+#             */
/*   Updated: 2024/12/06 05:11:30 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ps;
	unsigned char		uc;

	ps = s;
	uc = c;
	while (n > 0)
	{
		if (*ps == uc)
		{
			return ((void *) ps);
		}
		ps++;
		n--;
	}
	return (NULL);
}

/* int main()
{
	////////////////0123456789
	char *string = "Hello World!";
 	size_t len = strlen(string);
	int ch = 'l';

	void *result = memchr(string, ch, len);

	printf("%ld\n", (char *)result - string);
} */
