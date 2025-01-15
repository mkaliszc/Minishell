/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   milan.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:59:55 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/01/15 22:28:23 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "../OctoLIB/include/libft.h"

int		handle_in(t_mini *data);
int		handle_out(t_mini *data);
char	*handle_here_doc(char *limiter);