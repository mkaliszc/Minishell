/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   milan.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:59:55 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/18 20:58:40 by albillie         ###   ########.fr       */
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
}				t_data;
