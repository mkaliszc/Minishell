/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:59:55 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/22 21:42:20 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"
# include "structs.h"

void	executing_minishell(t_mini *data);
t_data	*init_struct(t_mini *data);
void	which_builtins(t_mini *data);
char	**lst_to_char(t_env *lst_env);
int		get_lst_env_size(t_env *lst_env);
void	close_unused_pipes(int *pipe_fd, int cur_cmd);
void	handle_pipe(t_mini *data, t_data *info, int cur_cmd);
void	handle_child(t_mini *data, int child_number, t_data	*info);
char	*handle_here_doc(char *limiter);
int		handle_redir_no_pipe(t_mini *data, t_data *info);
void	handle_redir(t_mini *data, int cmd_nbr, t_data *info);
void	loop(char **envp);
char	*validate_cmd_path(char **cmd, t_env *envp, t_mini *data);
void	perror_exit(t_mini *mini, char *error, int status);
void	handle_open(t_data *info, t_order_file *cur, int exit_code);
void	handle_file(t_mini *data, t_data *info);

// ? Free Functions

void	free_minishell(t_mini *mini);
void	free_env_struct(t_env *lst_env);
void	free_order_file_struct(t_order_file *order_file);
void	free_cmd_struct(t_lst_cmd *lst_cmd);
void	free_data_struct(t_data *data);

#endif
