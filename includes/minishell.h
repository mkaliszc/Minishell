/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 02:49:05 by albillie          #+#    #+#             */
/*   Updated: 2025/01/16 03:50:09 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#pragma once

#include "milan.h"
#include "alban.h"
#include "../OctoLIB/include/libft.h"
#include <stdbool.h>

typedef enum s_tokens
{
	WORD_TOK,
	CMD_TOK,
	IN_TOK,
	OUT_TOK,
	APP_TOK,
	HDC_TOK,
}	t_tokens;

typedef enum s_rd_file
{
	IN,
	OUT,
	HDC,
	APP,
}	t_rd_file;

typedef struct s_index
{
	int	in;
	int	out;
	int	append;
	int	here_d;
}			t_index;

/*
* chain of all env
*/
typedef struct 		s_env // ? Env variables list
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

/*
* struct s_hdc | give the order of here_doc to create
! in bash here_doc have high priority and are executed at first
! maybe try more
*/
typedef struct s_hdc
{
	char			*limiter;
	struct s_hdc	*next;
}					t_hdc;

/*
* struct s_order_in | give order for infile/here_doc redirection
* bool is_in |  true = infile / false = here_doc
* char *lmt_or_file | give the limiter of here_doc or file name for infile
* struct s_order_in *next | give you the next redirection to make
*/
typedef struct s_order_in
{
	char				*lmt_or_file;
	bool				is_in;
	struct s_order_in	*next;
}						t_order_in;

/*
* struct s_order_out | give order for outfile/append redirection
* bool  is_out | true = outfile / false = append
* char *file | define the name of the file
* struct s_order_out *next | give you the next redirection to make
*/
typedef struct s_order_file
{
	char				*file;
	t_rd_file			type;
	struct s_order_file	*next;
}						t_order_file;

/*
* struct s_lst_cmd | list all cmd in chain with her argument,
* all hdc, order of infile/hdc,order of out/appd and if this cmd or builtins
* char **cmd | table of cmd with her flags
* bool is_builtins | true = builtins / false = cmd
* t_hdc | see ref struct s_hdc
* t_order_in | see ref struct s_order_in
* t_order_out | see red struct t_order_out
*/
typedef struct s_lst_cmd
{
	char				**cmd;
	bool				is_builtins;
	struct s_lst_cmd	*next;
	t_hdc				*hdc;
	t_order_file		*order_file;
}						t_lst_cmd;

/*
* struct s_mini | give env variable nb of cmd and list of cmd
* int nb_cmd | give nb of cmd
* t_env | see ref struct s_env
* t_lst_cmd | see ref struct s_lst_cmd
*/
typedef struct s_mini
{
	t_env		*lst_env;
	t_lst_cmd	*lst_cmd;
	int			nb_cmd;
	int			exit_code;
}				t_mini;


void	update_env_paths(t_env *env);
t_env	*init_env_struct(char **envp);
t_env	*env_lst_new(char *data);
void	env_add_back(t_env **env, t_env *new);
void	handle_cd(char **cmd, t_env *env);
void	handle_export(char *cmd, t_env *env);
void	print_env_list(t_env *env);
