/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jojo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 03:11:39 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/15 03:10:47 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include "minishell.h"

/*
* j_loop for read the terminal
? Param (char **envp) environnement variable
? return nothing
*/
void	j_loop(char **envp);
t_mini	*create_m_shell(char **envp, char *ln_cmd);
t_env	*create_env(char *one_env);
t_env	*create_lst_env(char **envp);
void	lst_env_add_last(t_env **lst_env, t_env *env);
void	show_lst_env(t_env *lst_env);
void	free_lst_env(t_env *lst_env);
void	free_m_shell(t_mini *m_shell);
int		ft_strcmp(char *s1, char *s2);