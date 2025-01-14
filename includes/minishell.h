/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 02:49:05 by albillie          #+#    #+#             */
/*   Updated: 2025/01/14 13:33:19 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "jojo.h"
#include "milan.h"
#include "alban.h"

typedef	enum s_tokens
{
	WORD_TOK,
	CMD_TOK,
	IN_TOK,
	OUT_TOK,
	APP_TOK,
	HDC_TOK,
}		t_type;

typedef struct s_index
{
	int	in;
	int	out;
	int	append;
	int	here_d;
}			t_index;

typedef struct 		s_env // ? Env variables list
{
	char			*env;
	struct s_env	*next;
}					t_env;

typedef	struct		 s_mini // ? Main Minishell struct
{
	struct s_env	**env;
}					t_mini;


t_env	*init_env_struct(char **envp);;
t_env	*env_lst_new(char *data);
void	env_add_back(t_env **env, t_env *new);
void	print_env_list(t_env *env);
void	handle_cd(char **cmd, t_env *env);;
