/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:19:56 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/29 04:18:55 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_name(void)
{
	static int	i = 0;
	char		*name;
	char		*number;

	number = ft_itoa(i);
	if (!number)
		return (NULL);
	name = ft_strjoin("/tmp/here_doc_", number);
	free(number);
	i++;
	return (name);
}

int	write_to_here_doc(char *line, char *limiter, int tmp_fd)
{
	if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
	{
		close(tmp_fd);
		free(line);
		return (1);
	}
	ft_putendl_fd(line, tmp_fd);
	free(line);
	return (0);
}

char	*handle_here_doc(char *limiter)
{
	char	*name;
	int		tmp_fd;
	char	*line;
	g_signal_received = 2;

	name = get_name();
	tmp_fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (tmp_fd < 0)
	{
		free(name);
		return (NULL);
	}
	while (true)
	{
		ft_putstr_fd("> ", 1);
		line = get_next_line(0);
		if (g_signal_received == 0)
		{
			close(tmp_fd);
			free(name);
			break;
		}
		if (!line)
		{
			close(tmp_fd);
			break ;
		}
		if (write_to_here_doc(line, limiter, tmp_fd) == 1)
			return (name);
	}
	return (NULL);
}

int	process_here_doc(t_mini *mini)
{
	t_lst_cmd		*tmp;
	t_order_file	*cur;
	char			*name;

	tmp = mini->lst_cmd;
	while (tmp)
	{
		cur = tmp->order_file;
		while (cur)
		{
			if (cur->type == HDC)
			{
				name = handle_here_doc(cur->file);
				if (!name)
					return (1);
				free(cur->file);
				cur->file = name;
			}
			cur = cur->next;
		}
		tmp = tmp->next;
	}
	return (0);
}
