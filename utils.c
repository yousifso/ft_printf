/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygurma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:21:55 by ygurma            #+#    #+#             */
/*   Updated: 2023/03/22 19:33:26 by ygurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This code defines several helper functions for formatting 
 * and printing output to the standard output.
 * ft_putchar writes a single character to the standard output 
 * and increments a length counter.
 * ft_putnbr writes a given integer to the standard output 
 * and handles negative numbers and INT_MIN.
 * ft_putuns writes a given unsigned integer to the standard output.
 * ft_puthex writes a given unsigned long long integer 
 * as a hexadecimal string to the standard output,
 * handling lowercase and uppercase letters based on 
 * the format specifier provided.
 */

#include "ft_printf.h"

int	ft_putchar(char c, int *length)
{
	write(1, &c, 1);
	(*length)++;
	return (*length);
}

void	ft_putstr(char *s, int *length)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i], length);
		i++;
	}
}

void	ft_putnbr(int nb, int *length)
{
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-', length);
	}
	if (nb == -2147483648)
	{
		ft_putchar('2', length);
		nb = 147483648;
	}
	if (nb < 10)
		ft_putchar(nb + '0', length);
	else
	{
		ft_putnbr(nb / 10, length);
		ft_putnbr(nb % 10, length);
	}
}

void	ft_putuns(unsigned int nb, int *length)
{
	if (nb < 10)
		ft_putchar(nb + '0', length);
	else
	{
		ft_putuns(nb / 10, length);
		ft_putuns(nb % 10, length);
	}
}

/* This is a recursive function that converts a given 
 * unsigned long long integer `nb` into its hexadecimal 
 * representation and stores it in a string `str`. 
 * The function also updates the value of an integer 
 * pointer `length` to keep track of the length of the string.
 * The function works by recursively dividing the given number `nb` by 16,
 *  which is the base of hexadecimal numbers, 
 *  until the quotient becomes less than 16. The remainder 
 *  of each division is then converted to its corresponding hexadecimal 
 *  digit and stored in the string `str`.The function checks 
 *  if the hexadecimal digit is greater than 9 and less than 16, 
 *  in which case it converts it to a letter between 
 *  A and F if the first character of the string `str` 
 *  is not 'x' or 'p' (used for pointer addresses), 
 *  otherwise it converts it to a letter between a and f. 
 *  Otherwise, it converts the digit to its corresponding 
 *  character and stores it in the string `str`.
 *  The function `ft_putchar` is used to store each character 
 *  in the string `str` one by one, and the integer 
 *  pointer `length` is updated accordingly. */

void	ft_puthex(unsigned long long nb, int *length, char *str)
{
	if (nb >= 16)
	{
		ft_puthex(nb / 16, length, str);
		nb %= 16;
	}		
	if (nb > 9 && nb < 16)
	{
		if (*str == 'x' || *str == 'p')
			ft_putchar(nb % 10 + 97, length);
		else
			ft_putchar(nb % 10 + 65, length);
	}
	else
		ft_putchar(nb + '0', length);
}
