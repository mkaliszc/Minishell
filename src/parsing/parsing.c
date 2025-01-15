/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 03:14:14 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/14 19:57:02 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	readshell(char **envp)
{
	char *ln_cmd;
	ln_cmd = readline("$ ");
	printf("%s", ln_cmd);
	free(ln_cmd);
}