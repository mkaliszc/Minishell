/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:04:20 by albillie          #+#    #+#             */
/*   Updated: 2024/10/27 23:16:46 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(int c);
int		ft_print_str(char *str);
int		ft_print_nbr(int nbr);
int		ft_print_unsigned(unsigned int n);
int		ft_print_pointer(void *ptr);
int		ft_print_hex_low(unsigned int num);
int		ft_print_hex_up(unsigned int num);

#endif
