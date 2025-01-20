/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:19:07 by albillie          #+#    #+#             */
/*   Updated: 2024/10/27 13:11:18 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_low(unsigned int num)
{
	size_t	string_length;
	char	*hex;

	string_length = 0;
	hex = "0123456789abcdef";
	if (num >= 16)
	{
		string_length += ft_print_hex_low(num / 16);
	}
	string_length += write(1, &hex[num % 16], 1);
	return (string_length);
}

int	ft_print_hex_up(unsigned int num)
{
	size_t	string_length;
	char	*hex;

	string_length = 0;
	hex = "0123456789ABCDEF";
	if (num >= 16)
	{
		string_length += ft_print_hex_up(num / 16);
	}
	string_length += write(1, &hex[num % 16], 1);
	return (string_length);
}

/* int main()
{
	unsigned int a = 255;

	ft_printf("%X\n", a);
} */
