/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alban.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 05:23:08 by albillie          #+#    #+#             */
/*   Updated: 2025/01/16 14:50:24 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// INCLUDES

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdbool.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../OctoLIB/include/libft.h"
#include "minishell.h"

// COLORS

#define GREEN	"\e[0;32m"
#define END 	"\e[0m"

// BUILTINS FUNCTIONS

int	handle_pwd();
void	handle_echo(char **cmd);
void	handle_exit();
void	print_element(char **cmd);
