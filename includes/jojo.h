/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jojo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 03:11:39 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/17 03:41:42 by jbergos          ###   ########.fr       */
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
int		is_border_pipe(char *ln_cmd);
int		is_quote_closed(char *ln_cmd);
void	ft_error(char c);
int		is_good_angle_bracket(char *ln_cmd);
void	while_s_quote(char *ln_cmd, int *index);
void	while_d_quote(char *ln_cmd, int *index);
int		while_a_brck(char *ln_cmd, int *i, char *a_brck, int *cnt);
void	init_ft_brckt(int *i, int *cnt, char *a_brck);
int		is_dbl_pipe(char *ln_cmd);
void	split_cmd(char *ln_cmd);