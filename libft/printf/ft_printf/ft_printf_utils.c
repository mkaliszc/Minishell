/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 23:33:04 by albillie          #+#    #+#             */
/*   Updated: 2024/10/27 23:19:06 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_print_nbr(int nbr)
{
	int	print_length;

	print_length = 0;
	if (nbr == -2147483648)
	{
		return (ft_print_str("-2147483648"));
	}
	if (nbr < 0)
	{
		print_length += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		print_length += ft_print_nbr(nbr / 10);
		print_length += ft_putchar((nbr % 10) + '0');
	}
	else
	{
		print_length += ft_putchar(nbr + '0');
	}
	return (print_length);
}

int	ft_print_unsigned(unsigned int n)
{
	int	print_length;

	print_length = 0;
	if (n >= 10)
	{
		print_length += ft_print_unsigned(n / 10);
		print_length += ft_putchar((n % 10) + '0');
	}
	else
	{
		print_length += ft_putchar(n + '0');
	}
	return (print_length);
}
