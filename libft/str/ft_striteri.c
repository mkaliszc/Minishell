/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 23:41:10 by albillie          #+#    #+#             */
/*   Updated: 2024/12/06 05:11:30 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void	ft_striteri_test(unsigned int i, char *c)
{
	(void) i;
	if (*c >= 'a' || *c <= 'z')
	{
		*c -= 32;
	}
} */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/* int main()
{
	char string[] = "test";
	ft_striteri(string, ft_striteri_test);

	printf("%s\n", string);
} */
