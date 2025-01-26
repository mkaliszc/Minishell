/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 05:23:08 by albillie          #+#    #+#             */
/*   Updated: 2025/01/26 02:48:06 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

// # include "minishell.h"
# include "structs.h"
# include <stdbool.h>

void	update_env_pwds(t_env *env);
void	handle_home_event(t_mini *mini);
void	handle_cd(char **cmd, t_mini *mini);
bool	is_flag_here(char **cmd);
void	print_elements(char **cmd, bool flag);
void	handle_echo(char **cmd);
void	handle_env(t_env *env);
void	handle_exit(char **cmd, t_mini *mini);
void	handle_export(char **cmd, t_env **env);
void	handle_pwd(void);
void	free_env_part(t_env *env);
void	handle_unset(char **cmd, t_env **env);
int		cmd_array_size(char **array);

#endif
