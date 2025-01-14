/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 02:49:05 by albillie          #+#    #+#             */
/*   Updated: 2025/01/14 19:10:18 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "jojo.h"
#include "milan.h"
#include "alban.h"
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
typedef struct s_env
{
	char			*env;
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
typedef struct s_order_out
{
	char				*file;
	bool				is_out;
	struct s_order_out	*next;
}						t_order_out;

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
	t_hdc				**hdc;
	t_order_in			**order_in;
	t_order_out			**order_out;
}						t_lst_cmd;

/*
* struct s_mini | give env variable nb of cmd and list of cmd
* int nb_cmd | give nb of cmd
* t_env | see ref struct s_env
* t_lst_cmd | see ref struct s_lst_cmd
*/
typedef struct s_mini
{
	t_env		**env;
	t_lst_cmd	**cmd;
	int			nb_cmd;
}				t_mini;