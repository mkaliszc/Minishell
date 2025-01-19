/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 00:29:40 by albillie          #+#    #+#             */
/*   Updated: 2025/01/19 06:30:46 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "builtins.h"
# include "exec.h"
# include "parsing.h"
# include "../OctoLIB/include/libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>

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

typedef struct s_env
{
	char				*key;
	char				*value;
	struct s_env		*next;
}						t_env;

typedef struct s_order_file
{
	char				*file;
	t_rd_file			type;
	struct s_order_file	*next;
}						t_order_file;

typedef struct s_lst_cmd
{
	char				**cmd;
	bool				is_builtins;
	struct s_lst_cmd	*next;
	t_order_file		*order_file;
}						t_lst_cmd;

typedef struct s_mini
{
	t_env				*lst_env;
	t_lst_cmd			*lst_cmd;
	int					nb_cmd;
	int					exit_code;
}						t_mini;

typedef struct s_data
{
	int					in_fd;
	int					out_fd;
	pid_t				*pid;
	int					*pipe_fd;
}						t_data;

#endif
