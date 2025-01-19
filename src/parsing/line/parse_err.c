/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 00:16:31 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/17 00:17:32 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_error(char c)
{
	ft_putstr_fd("miniwilds: syntax error near unexpected token `", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\'\n", 2);
}
