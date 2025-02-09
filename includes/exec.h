/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:59:55 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/29 22:34:14 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

// # include "minishell.h"
# include "structs.h"

void	executing_minishell(t_mini *data);
t_data	*init_struct(t_mini *data);
void	which_builtins(t_mini *data, t_lst_cmd *tmp);
char	**lst_to_char(t_env *lst_env);
int		get_lst_env_size(t_env *lst_env);
void	handle_pipe(t_mini *data, t_data *info, int cur_cmd, t_lst_cmd *tmp);
void	handle_child(t_mini *data, int cmd_nbr, t_data	*info, t_lst_cmd *tmp);
char	*handle_here_doc(char *limiter, t_mini *mini);
void	handle_redir_no_pipe(t_mini *data, t_data *info, t_lst_cmd *tmp);
void	handle_redir(t_mini *data, int cmd_nbr, t_data *info, t_lst_cmd *tmp);
void	loop(char **envp);
char	*validate_cmd_path(char **cmd, t_env *envp, t_mini *mini);
void	perror_exit(t_mini *mini, char *error, int status);
void	handle_open(t_data *info, t_order_file *cur, int exit_code);
void	handle_file(t_mini *data, t_data *info, t_lst_cmd *tmp);
int		process_here_doc(t_mini *mini);
void	unlinks_here_doc(t_data *data);
void	handle_redir_out(t_mini *data, int cmd_nbr, t_data *info);
void	check_close(t_data *data);

// ? Free Functions

void	free_minishell(t_mini *mini);
void	free_env_struct(t_env *lst_env);
void	free_order_file_struct(t_order_file *order_file);
void	free_cmd_struct(t_lst_cmd *lst_cmd);
void	free_data_struct(t_data *data);

#endif
