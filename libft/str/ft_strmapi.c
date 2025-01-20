/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:37:02 by albillie          #+#    #+#             */
/*   Updated: 2024/12/06 05:11:29 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* char	ft_mapping_test(unsigned int i, char c)
{
	(void) i;
	if (c >= 'a' && c <= 'z')
	{
		c -= 32;
	}
	return (c);
} */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	result = (char *) malloc ((ft_strlen(s) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

/* int main()
{
	char *string = "kaveO le goat";
	char *result = ft_strmapi(string, ft_mapping_test);

	printf("%s\n", result);
} */
