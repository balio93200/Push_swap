/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balio932 <balio932@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:04:09 by balio932          #+#    #+#             */
/*   Updated: 2024/10/09 17:33:31 by balio932         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr_upper_hex(unsigned int nbr)
{
	char	*hex_digits;
	int		count;

	count = 0;
	hex_digits = "0123456789ABCDEF";
	if (nbr >= 16)
		count = count + ft_putnbr_upper_hex(nbr / 16);
	count = count + ft_putchar(hex_digits[nbr % 16]);
	return (count);
}

int	ft_putnbr_hex(unsigned long nbr)
{
	char	*hex_digits;
	int		count;

	count = 0;
	hex_digits = "0123456789abcdef";
	if (nbr >= 16)
		count = count + ft_putnbr_hex(nbr / 16);
	count = count + ft_putchar(hex_digits[nbr % 16]);
	return (count);
}

int	ft_print_pointer(void *ptr)
{
	unsigned long	address;
	int				count;

	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	address = (unsigned long)ptr;
	count = 0;
	count = count + ft_putstr("0x");
	count = count + ft_putnbr_hex(address);
	return (count);
}

int	ft_strlen_printf(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
