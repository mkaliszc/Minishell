/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_order_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 01:03:50 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/23 04:23:49 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

void	show_order_file(t_order_file *ord_f)
{
	t_order_file	*tmp;

	if (!ord_f)
	{
		printf("yolo\n");
		return ;
	}
	tmp = ord_f;
	while (tmp)
	{
		if (tmp->type == IN)
			printf("infile : |%s|\n", tmp->file);
		if (tmp->type == OUT)
			printf("outfile : |%s|\n", tmp->file);
		if (tmp->type == HDC)
			printf("outfile : |%s|\n", tmp->file);
		if (tmp->type == APP)
			printf("append : |%s|\n", tmp->file);
		tmp = tmp->next;
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

t_order_file	*create_lst_order_file(char *one_cmd, t_env *env)
{
	t_order_file	*order_file;
	int				i;

	i = 0;
	order_file = NULL;
	while (one_cmd[i])
	{
		if (one_cmd[i] == '"')
			while_d_quote(one_cmd, &i);
		else if (one_cmd[i] == '\'')
			while_s_quote(one_cmd, &i);
		else if (one_cmd[i] == '<')
			redir_in_hdc(&order_file, one_cmd, &i, env);
		else if (one_cmd[i] == '>')
			redir_out_app(&order_file, one_cmd, &i, env);
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
