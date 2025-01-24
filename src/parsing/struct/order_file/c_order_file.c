/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_order_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 01:03:50 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/24 02:49:30 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

void	show_order_file(t_order_file *ord_f)
{
	t_order_file	*tmp;
	int				i;

	if (!ord_f)
	{
		printf("no redirextion for this cmd \n");
		return ;
	}
	tmp = ord_f;
	i = 0;
	while (tmp)
	{
		if (tmp->type == IN)
			printf("infile number |%d| : |%s|\n", i + 1, tmp->file);
		if (tmp->type == OUT)
			printf("outfile number |%d| : |%s|\n", i + 1, tmp->file);
		if (tmp->type == HDC)
			printf("outfile number |%d| : |%s|\n", i + 1, tmp->file);
		if (tmp->type == APP)
			printf("append number |%d| : |%s|\n", i + 1, tmp->file);
		tmp = tmp->next;
		++i;
	}
}

t_order_file	*create_order_file(char *file, t_rd_file type)
{
	t_order_file	*order_file;

	order_file = malloc(sizeof(t_order_file));
	if (!order_file)
		return (NULL);
	order_file->file = file;
	order_file->type = type;
	order_file->next = NULL;
	return (order_file);
}

void	order_file_add_lst(t_order_file **order_file, t_order_file *file)
{
	t_order_file	*tmp;

	if (!(*order_file))
	{
		*order_file = file;
		return ;
	}
	tmp = *order_file;
	while (tmp)
	{
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
	tmp->next = file;
}

t_order_file	*create_lst_order_file(char *one_cmd, t_mini *m_shell)
{
	t_order_file	*order_file;
	int				i;

	i = 0;
	order_file = NULL;
	while (one_cmd[i])
	{
		if (one_cmd[i] == '"' || one_cmd[i] == '\'')
		{
			if (one_cmd[i] == '\'')
				while_s_quote(one_cmd, &i);
			else
				while_d_quote(one_cmd, &i);
			++i;
		}
		else if (one_cmd[i] == '<')
			redir_in_hdc(&order_file, one_cmd, &i, m_shell);
		else if (one_cmd[i] == '>')
			redir_out_app(&order_file, one_cmd, &i, m_shell);
		else
			++i;
	}
	return (order_file);
}

void	free_order_file(t_order_file *ord_f)
{
	if (!ord_f)
		return ;
	free_order_file(ord_f->next);
	if (ord_f->file)
		free(ord_f->file);
	free(ord_f);
}
