/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:14:14 by marcogar          #+#    #+#             */
/*   Updated: 2023/05/11 17:10:31 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char *format, va_list arguments)
{
	int	counter;

	counter = 0;
	if (*format == 'c')
		counter += ft_putchar_pf(va_arg(arguments, int));
	else if (*format == 's')
		counter += ft_putstr_pf(va_arg(arguments, char *));
	else if (*format == 'p')
		counter += ft_putptr_pf(va_arg(arguments, unsigned long long));
	else if (*format == 'd' || *format == 'i')
		counter += ft_putnbr_pf(va_arg(arguments, int));
	else if (*format == 'u')
		counter += ft_putunint_pf(va_arg(arguments, unsigned int));
	else if (*format == 'x' || *format == 'X')
		counter += ft_puthexa_pf(va_arg(arguments, unsigned int), *format);
	else if (*format == '%')
		counter += ft_putchar_pf(*format);
	else
		return (0);
	return (counter);
}

int	ft_printf(char const *format, ...)
{
	int		counter;
	va_list	arguments;

	va_start(arguments, format);
	counter = 0;
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			counter += ft_format((char *)format, arguments);
		}
		else
			counter += ft_putchar_pf(*format);
		++format;
	}
	va_end(arguments);
	return (counter);
}
