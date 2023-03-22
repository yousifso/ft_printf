/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygurma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:34:36 by ygurma            #+#    #+#             */
/*   Updated: 2023/03/20 19:02:35 by ygurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This function generates a formatted string based on a given format string and
 * additional arguments. The implementation is split into two parts: the
 * ft_printf function initializes a va_list object and calls a separate
 * function to generate the output string based on the format string. */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		length;

	length = 0;
	va_start(arguments, format);
	length = parse_input(format, arguments, length);
	va_end(arguments);
	return (length);
}
