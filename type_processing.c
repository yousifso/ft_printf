/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygurma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:58:54 by ygurma            #+#    #+#             */
/*   Updated: 2023/03/17 19:59:19 by ygurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This code defines several handler functions 
 * for different format specifiers used in the ft_printf function. 
 * The c_type function handles the %c specifier, s_type 
 * handles the %s specifier, d_i_type handles the %d and %i specifiers, 
 * and u_type handles the %u specifier. Each function takes 
 * in a va_list of arguments and a pointer to an integer 
 * representing the length of the output, and performs 
 * the necessary conversion and output using helper functions 
 * defined in the ft_printf.h header file. */

#include "ft_printf.h"

void	c_type(va_list arguments, int *length)
{
	char	c;

	c = va_arg(arguments, int);
	ft_putchar(c, length);
}

void	s_type(va_list arguments, int *length)
{
	char	*s;

	s = va_arg(arguments, char *);
	if (!s)
		s = "(null)";
	while (*s)
		ft_putchar(*s++, length);
}

void	d_i_type(va_list arguments, int *length)
{
	int	nb;

	nb = va_arg(arguments, int);
	ft_putnbr(nb, length);
}

void	u_type(va_list arguments, int *length)
{
	unsigned int	nb;

	nb = va_arg(arguments, unsigned int);
	ft_putuns(nb, length);
}
