/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_processing_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygurma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:00:11 by ygurma            #+#    #+#             */
/*   Updated: 2023/03/22 19:28:14 by ygurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This code defines two handler functions for formatting and printing
 * hexadecimal values to the standard output. The `x_type` function reads an 
 * unsigned integer argument from the `va_list` and passes it to the `ft_puthex`
 * function to convert the value to hexadecimal format and output it to the 
 * standard output using the `ft_putchar` helper function. The `p_type` function 
 * reads an unsigned long long argument from the `va_list` and outputs the 
 * hexadecimal representation of the memory address pointed to by the argument 
 * by prepending '0x' to the hexadecimal value. The `ft_puthex` function is used 
 * to convert the value to hexadecimal format. */

#include "ft_printf.h"

void	x_type(va_list arguments, int *length, char *str)
{
	unsigned int	nb;

	nb = va_arg(arguments, unsigned int);
	ft_puthex(nb, length, str);
}

void	p_type(va_list arguments, int *length, char *str)
{
	unsigned long long	adr;

	adr = va_arg(arguments, unsigned long long);
	if (adr == 0)
	{
		ft_putstr("(nil)", length);
	}
	else
	{
		ft_putchar('0', length);
		ft_putchar('x', length);
		ft_puthex(adr, length, str);
	}
}
