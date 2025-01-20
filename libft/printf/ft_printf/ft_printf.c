/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:02:36 by albillie          #+#    #+#             */
/*   Updated: 2024/10/27 23:19:11 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_handler(va_list args, char str)
{
	size_t	print_length;

	print_length = 0;
	if (str == 'c')
		print_length += ft_putchar(va_arg(args, int));
	else if (str == 's')
		print_length += ft_print_str(va_arg(args, char *));
	else if (str == 'p')
		print_length += ft_print_pointer(va_arg(args, void *));
	else if (str == 'd' || str == 'i')
		print_length += ft_print_nbr(va_arg(args, int));
	else if (str == 'u')
		print_length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (str == 'x')
		print_length += ft_print_hex_low(va_arg(args, unsigned int));
	else if (str == 'X')
		print_length += ft_print_hex_up(va_arg(args, unsigned int));
	else if (str == '%')
		print_length += ft_putchar('%');
	return (print_length);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	print_length;
	va_list	args;

	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_length += ft_format_handler(args, str[i + 1]);
			i++;
		}
		else
		{
			print_length += ft_putchar(str[i]);
		}
		i++;
	}
	va_end(args);
	return (print_length);
}

/* int main()
{
	int num = 14;

	ft_printf("%c\n%s\n%i\n%d\n", 'c', "string", num, num);
} */
