/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:08:33 by loribeir          #+#    #+#             */
/*   Updated: 2024/11/24 16:08:39 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

# define HEX_UPPER "0123456789ABCDEF"
# define HEX_LOWER "0123456789abcdef"

int		ft_printf(const char *specifier, ...);
int		check_specifier(va_list args, char spec, int *count);
/* ------------ */
void	ft_print_str(char *str, int *count);
void	ft_print_char(char c, int *count);
void	ft_putchar(char c);
void	ft_print_ptr(unsigned long ptr, int *count);
void	ft_print_decimal(int nb, int *count);
void	ft_print_unsigned_dec(unsigned int nb, int *count);
void	ft_print_upper_hex(int nb, int *count);
void	ft_print_lower_hex(int nb, int *count);
void	ft_print_sign(int *count);

#endif