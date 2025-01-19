/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 05:23:08 by albillie          #+#    #+#             */
/*   Updated: 2025/01/19 05:07:19 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

// ? Includes

#include "minishell.h"
#include "structs.h"
# include <stdbool.h>

// ? Colors

#define GREEN	"\e[0;32m"
#define END 	"\e[0m"

// ? Functions

void	update_env_pwds(t_env *env);
void	handle_home_event(t_env *env);
void	handle_cd(char **cmd, t_env *env);
bool	is_flag_here(char **cmd);
void	print_elements(char **cmd, bool flag);
void	handle_echo(char **cmd);
void	handle_env(t_env *env);
void	handle_exit(char **cmd);
int		handle_export(char **cmd, t_env **env);
void	handle_pwd(void);
void	free_test(t_env *env);
void	handle_unset(char **cmd, t_env **env);
int		cmd_array_size(char **array);

#endif
