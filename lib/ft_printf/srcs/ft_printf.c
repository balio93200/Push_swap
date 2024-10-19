/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balio932 <balio932@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 02:36:46 by balio932          #+#    #+#             */
/*   Updated: 2024/10/09 17:33:41 by balio932         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	ft_putstr(char *str)
{
	int	i;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = ft_strlen_printf(str);
	write(1, str, i);
	return (i);
}

int	ft_putnbr_u(unsigned int nb)
{
	int				count;
	unsigned long	nbr;

	count = 0;
	nbr = nb;
	if (nbr > 9)
	{
		count = count + ft_putnbr(nbr / 10);
	}
	count = count + ft_putchar(nbr % 10 + '0');
	return (count);
}

int	ft_putnbr(int nb)
{
	int		count;
	long	nbr;

	count = 0;
	nbr = nb;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		count = count + ft_putchar('-');
	}
	if (nbr > 9)
	{
		count = count + ft_putnbr(nbr / 10);
	}
	count = count + ft_putchar(nbr % 10 + '0');
	return (count);
}

int	check_format(va_list args, char c)
{
	int	count;

	count = 0;
	if (c == 'd' || c == 'i')
		count = count + ft_putnbr(va_arg(args, int));
	else if (c == 's')
		count = count + ft_putstr(va_arg(args, char *));
	else if (c == 'c')
		count = count + ft_putchar(va_arg(args, int));
	else if (c == 'x')
		count = count + ft_putnbr_hex(va_arg(args, unsigned));
	else if (c == 'p')
		count = count + ft_print_pointer(va_arg(args, void *));
	else if (c == 'u')
		count = count + ft_putnbr_u(va_arg(args, unsigned));
	else if (c == 'X')
		count = count + ft_putnbr_upper_hex(va_arg(args, unsigned));
	else if (c == '%')
		count = count + ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (format == NULL)
		return (-1);
	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			count = count + check_format(args, format[++i]);
		else
			count = count + ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
