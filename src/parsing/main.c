/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:53:13 by jbergos           #+#    #+#             */
/*   Updated: 2025/01/15 00:58:08 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/jojo.h"

int	main(int argc, char *argv[], char **envp)
{
	(void)argc;
	(void)argv;
	j_loop(envp);
	return (0);
}
