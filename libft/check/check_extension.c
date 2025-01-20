/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:10:38 by albillie          #+#    #+#             */
/*   Updated: 2024/12/06 05:11:31 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	check_extension(char *filename, char *extension)
{
	const char	*dot;

	if (!filename || !extension)
		return (false);
	dot = strrchr(filename, '.');
	if (!dot)
		return (false);
	return ((strcmp(dot + 1, extension)) == 0);
}
