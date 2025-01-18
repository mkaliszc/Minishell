/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 06:39:43 by albillie          #+#    #+#             */
/*   Updated: 2025/01/18 06:37:49 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_pwd()
{
	char	*cwd;

	cwd = NULL;
	cwd = getcwd(cwd, 0);
	if (!cwd)
	{
		perror("pwd");
	}
	printf("%s\n", cwd);
	if (cwd)
	{
		free(cwd);
	}
}
