/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 22:01:17 by albillie          #+#    #+#             */
/*   Updated: 2024/12/06 05:11:31 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
/*
int main()
{
	char string[10] = "test4141";
	ft_bzero(string, 4);
	printf("%s%s\n", "My Function Test : ", string);

	char string1[10] = "test4141";
	bzero(string1 + 6, 4);
	printf("%s%s\n", "Official Function Test : ", string1);
}
*/
