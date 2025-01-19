/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   milan.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:59:55 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/19 01:10:55 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "../OctoLIB/include/libft.h"
# include "minishell.h"

typedef struct s_data
{
	int		in_fd;
	int		out_fd;
	pid_t	*pid;
	int		*pipe_fd;
}				t_data;


int		handle_in(t_mini *data);
int		handle_out(t_mini *data);
char	*handle_here_doc(char *limiter);
int		handle_redir_no_pipe(t_mini *data);
void	which_builtins(t_mini *data);
char	*get_path(char **cmd, t_env *envp);