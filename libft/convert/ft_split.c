/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 02:00:38 by albillie          #+#    #+#             */
/*   Updated: 2024/12/06 05:11:31 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(const char *s, char c)
{
	size_t	count;

	if (!s)
	{
		return (0);
	}
	count = 0;
	while (*s)
	{
		while (*s == c)
		{
			s++;
		}
		if (*s)
		{
			count++;
		}
		while (*s && *s != c)
		{
			s++;
		}
	}
	return (count);
}

static char	*ft_word_filler(const char *s, char c)
{
	char	*word;
	size_t	len;
	size_t	i;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	ft_free_array(char **array, size_t i)
{
	while (i--)
	{
		free(array[i]);
	}
	free(array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	i;

	array = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			array[i] = ft_word_filler(s, c);
			if (!array[i])
				return (ft_free_array(array, i), NULL);
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	array[i] = NULL;
	return (array);
}

/* int main()
{
	char **result;
	size_t i = 0;

	result = ft_split("hello!zzzzouizzzz", 'z');
	if (!result)
		return (1);

	while (result[i])
	{
		printf("%s\n", result[i]);
		i++;
	}
} */
