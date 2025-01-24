/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 03:11:39 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/24 04:16:18 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

// # include "minishell.h"
# include "structs.h"

/*
* j_loop for read the terminal
? Param (char **envp) environnement variable
? return nothing
*/
void			j_loop(t_mini *m_shell);
t_env			*create_env(char *one_env);
t_env			*create_lst_env(char **envp);
void			lst_env_add_last(t_env **lst_env, t_env *env);
void			show_all_lst_env(t_env *lst_env);
void			free_lst_env(t_env *lst_env);
void			free_m_shell(t_mini *m_shell);
t_mini			*create_m_shell_env(char**envp);
int				find_occ(char *s, char c);
char			*key_env(char *s);
int				empty_line(char *ln_cmd);
void			find_n_replace_var(t_mini *m_shell, char *ln_cmd);
int				ft_strcmp(char *s1, char *s2);
void			show_one_lst_env(t_env *lst_env, char *key);
t_env			*find_one_lst_env(t_env *lst_env, char *key);
void			u_r_one_lst_env(t_env *lst_env, char *export);
void			create_one_lst_env(t_env *lst_env, char *export);
int				is_border_pipe(char *ln_cmd);
int				is_quote_closed(char *ln_cmd);
void			ft_error(char c);
int				is_good_angle_bracket(char *ln_cmd);
void			while_s_quote(char *ln_cmd, int *index);
void			while_d_quote(char *ln_cmd, int *index);
int				while_a_brck(char *ln_cmd, int *i, char *a_brck, int *cnt);
void			init_ft_brckt(int *i, int *cnt, char *a_brck);
int				is_dbl_pipe(char *ln_cmd);
char			**split_cmd(char *ln_cmd);
void			add_lst_cmd(t_mini *m_shell, char *ln_cmd);
void			show_split(char **c_split);
void			free_split(char **c_split);
t_lst_cmd		*create_lst_cmd(char **cmd_split, t_mini *m_shell);
char			**table_cmd(char *cmd, t_mini *m_shell);
void			order_file_add_lst(t_order_file **order_file, t_order_file *file);
t_order_file	*create_order_file(char *file, t_rd_file type);
t_order_file	*create_lst_order_file(char *one_cmd, t_mini *m_shell);
void			redir_in_hdc(t_order_file **ord_f, char *cmd, int *i, t_mini *m_shell);
void			redir_out_app(t_order_file **ord_f, char *cmd, int *i, t_mini *m_shell);
void			show_order_file(t_order_file *ord_f);
int				nb_cmd(t_lst_cmd *cmd);
void			free_order_file(t_order_file *ord_f);
void			free_lst_cmd(t_lst_cmd	*cmd);
void			reset_m_shell(t_mini *m_shell);
int				length_without_quote(char *s);
char			*get_env(t_env *lst_env, char *s);
int				length_o_var(char *s, t_mini *m_shell);
char			*replace_o_var(char *s, t_mini *m_shell);
void			show_lst_cmd(t_lst_cmd	*lst_cmd);
void			parsing_shell(t_mini *m_shell, char *ln_cmd);
void			show_m_shell(t_mini	*m_shell);
bool			is_builtins(char *cmd);
void			length_exit_code(int code, int *i, int *len);
void			rep_exit_code(int code, char *new, t_pain *pain);
#endif
