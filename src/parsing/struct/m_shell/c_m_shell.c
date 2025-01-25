/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_m_shell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:23:21 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/25 22:41:37 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

void	show_lst_cmd(t_lst_cmd	*lst_cmd)
{
	t_lst_cmd	*tmp;
	int			i;

	if (!lst_cmd)
		return ;
	tmp = lst_cmd;
	i = 0;
	while (tmp)
	{
		printf("lst cmd and redir for pipe number |%d|\n", i + 1);
		printf("\n-----------------------------------------------\n");
		printf("------------list of cmd and args-----------\n");
		tmp->is_builtins ? printf("Is a builtins\n") : printf("Not a builtins\n");
		show_split(tmp->cmd);
		printf("-------------list of order file ------------------\n");
		show_order_file(tmp->order_file);
		printf("\n---------------------------------------\n");
		tmp = tmp->next;
		++i;
	}
}

void	add_lst_cmd(t_mini *m_shell, char *ln_cmd)
{
	char	**cmd_split;

	cmd_split = split_cmd(ln_cmd);
	m_shell->lst_cmd = create_lst_cmd(cmd_split, m_shell);
	m_shell->nb_cmd = nb_cmd(m_shell->lst_cmd);
	m_shell->exit_code = 0;
	free_split(cmd_split);
}

t_mini	*create_m_shell_env(char**envp)
{
	t_mini	*m_shell;

	m_shell = malloc(sizeof(t_mini));
	if (!m_shell)
		return (NULL);
	m_shell->lst_env = create_lst_env(envp);
	m_shell->exit_code = 0;
	m_shell->nb_cmd = 0;
	m_shell->lst_cmd = NULL;
	m_shell->data = NULL;
	return (m_shell);
}

void	free_m_shell(t_mini *m_shell)
{
	free_lst_env(m_shell->lst_env);
	free(m_shell);
}

void	reset_m_shell(t_mini *m_shell)
{
	m_shell->nb_cmd = 0;
	free_cmd_struct(m_shell->lst_cmd);
	free_data_struct(m_shell->data);
	m_shell->data = NULL;
	m_shell->lst_cmd = NULL;
}
