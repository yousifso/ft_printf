/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygurma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:44:17 by ygurma            #+#    #+#             */
/*   Updated: 2023/03/20 19:57:26 by ygurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This function takes a character pointer `str`, 
 * an integer pointer `length`, and a `va_list` 
 * variable `arguments` as arguments. It parses 
 * the character pointed to by `str` to determine 
 * the type of conversion to be performed, 
 * and calls the appropriate conversion 
 * function to handle the conversion.
 * The function first checks if the character 
 * pointed to by `str` is 'c', 's', 'd', 'i', 
 * 'u', 'x', 'X', or 'p'. If the character 
 * is 'c', it calls a function `c_type` 
 * to handle the conversion of a single character. 
 * If the character is 's', it calls a function 
 * `s_type` to handle the conversion of a string. 
 * If the character is 'd' or 'i', it calls a function 
 * `d_i_type` to handle the conversion of a 
 * signed decimal integer. If the character is 'u', 
 * it calls a function `u_type` to handle the conversion 
 * of an unsigned decimal integer. If the character 
 * is 'x' or 'X', it calls a function `x_type` 
 * to handle the conversion of an unsigned integer in 
 * hexadecimal format. If the character is 'p', 
 * it calls a function `p_type` to handle the 
 * conversion of a pointer address. 
 * If the character is none of the above, 
 * it simply calls a function `ft_putchar` 
 * to output the character to the standard output.*/

#include "ft_printf.h"

void	parse_conversions(char *str, int *length, va_list arguments)
{
	if (*str == 'c')
		c_type(arguments, length);
	else if (*str == 's')
		s_type(arguments, length);
	else if (*str == 'd' || *str == 'i')
		d_i_type(arguments, length);
	else if (*str == 'u')
		u_type(arguments, length);
	else if (*str == 'x' || *str == 'X')
		x_type(arguments, length, str);
	else if (*str == 'p')
		p_type(arguments, length, str);
	else
		ft_putchar(*str, length);
}

/* This function takes a string `str`, a `va_list` variable `arguments`, 
 * and an integer `length` as arguments. It iterates through 
 * the input string `str`character by character, 
 * and if it encounters a '%' character, it calls 
 * the `parse_conversions` function to handle 
 * the conversion. If it encounters any other character, 
 * it simply calls the `ft_putchar` function to output 
 * the character to the standard output.
 * The function updates the value of `length` 
 * to keep track of the number of characters written 
 * to the standard output, and returns the final value 
 * of `length` after all conversions and outputs are completed. */

int	parse_input(const char *str, va_list arguments, int length)
{
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			parse_conversions((char *)str, &length, arguments);
			str++;
		}
		else
			ft_putchar(*str++, &length);
	}
	return (length);
}
