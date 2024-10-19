/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balio932 <balio932@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:54:48 by balio932          #+#    #+#             */
/*   Updated: 2024/10/09 17:33:48 by balio932         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_putchar(char c);
int	ft_putnbr_upper_hex(unsigned int nbr);
int	ft_putnbr_hex(unsigned long nbr);
int	ft_print_pointer(void *ptr);
int	ft_strlen_printf(char *str);
int	ft_putstr(char *str);
int	ft_putnbr(int nb);
int	ft_putnbr_u(unsigned int nb);
int	check_format(va_list args, char c);
int	ft_printf(const char *format, ...);
#endif