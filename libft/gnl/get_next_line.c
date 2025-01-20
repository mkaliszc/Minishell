/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 01:53:11 by albillie          #+#    #+#             */
/*   Updated: 2024/12/06 05:11:31 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fill_line_buffer(int fd, char *left_c)
{
	char	*buffer;
	char	*temp;
	ssize_t	b_read;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (!left_c)
		left_c = ft_strdup("");
	if (!left_c)
		return (free(buffer), NULL);
	b_read = 1;
	while (b_read > 0 && !ft_strchr(left_c, '\n'))
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
			return (free(buffer), free(left_c), NULL);
		buffer[b_read] = '\0';
		temp = left_c;
		left_c = ft_strjoin(left_c, buffer);
		free(temp);
		if (!left_c)
			return (free(buffer), NULL);
	}
	return (free(buffer), left_c);
}

char	*extract_line(char *left_c)
{
	char	*line;
	int		i;

	i = 0;
	if (!left_c[0])
		return (NULL);
	while (left_c[i] && left_c[i] != '\n')
		i++;
	if (left_c[i] == '\n')
		i++;
	line = ft_substr(left_c, 0, i);
	return (line);
}

char	*update_left_c(char *left_c)
{
	char	*new_left;
	int		i;
	int		j;

	i = 0;
	while (left_c[i] && left_c[i] != '\n')
		i++;
	if (!left_c[i])
		return (NULL);
	i++;
	new_left = (char *)malloc(sizeof(char) * (ft_strlen(left_c) - i + 1));
	if (!new_left)
		return (NULL);
	j = 0;
	while (left_c[i])
		new_left[j++] = left_c[i++];
	new_left[j] = '\0';
	return (new_left);
}

char	*get_next_line(int fd)
{
	static char	*left_c;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(left_c);
		left_c = NULL;
		return (NULL);
	}
	left_c = fill_line_buffer(fd, left_c);
	if (!left_c)
		return (NULL);
	line = extract_line(left_c);
	if (!line)
	{
		free(left_c);
		left_c = NULL;
		return (NULL);
	}
	temp = left_c;
	left_c = update_left_c(left_c);
	free(temp);
	return (line);
}
