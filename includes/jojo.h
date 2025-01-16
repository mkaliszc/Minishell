/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jojo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 03:11:39 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/16 06:18:29 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>

typedef enum s_tokens t_tokens;
typedef enum s_rd_file t_rd_file;
typedef struct s_index t_index;
typedef struct s_env t_env;
typedef struct s_hdc t_hdc;
typedef struct s_order_file t_order_file;
typedef struct s_lst_cmd t_lst_cmd;
typedef struct s_mini t_mini;

typedef struct s_mini t_mini;
typedef struct s_env t_env;
/*
* j_loop for read the terminal
? Param (char **envp) environnement variable
? return nothing
*/
void	j_loop(t_mini *m_shell);
t_mini	*create_m_shell(char **envp, char *ln_cmd);
t_env	*create_env(char *one_env);
t_env	*create_lst_env(char **envp);
void	lst_env_add_last(t_env **lst_env, t_env *env);
void	show_all_lst_env(t_env *lst_env);
void	free_lst_env(t_env *lst_env);
void	free_m_shell(t_mini *m_shell);
t_mini	*create_m_shell_env(char**envp);
int		find_occ(char *s, char c);
char	*key_env(char *s);
int		empty_line(char *ln_cmd);
void	find_n_replace_var(t_mini *m_shell, char *ln_cmd);
int		ft_strcmp(char *s1, char *s2);
void	show_one_lst_env(t_env *lst_env, char *key);
t_env	*find_one_lst_env(t_env *lst_env, char *key);
void	u_r_one_lst_env(t_env *lst_env, char *export);
void	create_one_lst_env(t_env *lst_env, char *export);
