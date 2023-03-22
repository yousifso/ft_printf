/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygurma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:11:55 by ygurma            #+#    #+#             */
/*   Updated: 2023/03/22 19:27:20 by ygurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This header file contains declarations 
 * for a custom printf function,
 * as well as several utility functions used by 
 * the implementation. The main
 * function, ft_printf, takes a format string 
 * and additional arguments, and
 * generates a formatted string based on the specified format. 
 * The implementation of ft_printf is split across several files. 
 * This header declares the functions
 * used to parse the format string and generate the output string. 
 * Additionally,this header declares utility functions 
 * for outputting characters, integers,
 * unsigned integers, and hexadecimal numbers, 
 * as well as a function for outputtingpointers. */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int				ft_printf(const char *format, ...);

int				parse_input(const char *str, va_list arguments, int length);
void			parse_conversions(char *str, int *length, va_list arguments);
void			c_type(va_list arguments, int *length);
void			s_type(va_list arguments, int *length);
void			d_i_type(va_list arguments, int *length);
void			u_type(va_list arguments, int *length);
void			x_type(va_list arguments, int *length, char *str);
void			p_type(va_list arguments, int *length, char *str);
int				ft_putchar(char c, int *length);
void			ft_putnbr(int nb, int *length);
void			ft_putuns(unsigned int nb, int *length);
void			ft_puthex(unsigned long long nb, int *length, char *str);
void			ft_putstr(char *s, int *length);

#endif
