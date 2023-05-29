/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:55:23 by marcogar          #+#    #+#             */
/*   Updated: 2023/05/11 12:52:46 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_pf(int n)
{
	int	counter;

	counter = 0;
	if (n == -2147483648)
	{
		n = -n;
		counter += write(1, "-", 1);
		counter += write(1, "2", 1);
		counter += ft_putnbr_pf(147483648);
	}
	else if (n < 0)
	{
		n = -n;
		counter += write(1, "-", 1);
		counter += ft_putnbr_pf(n);
	}
	else if (n >= 0 && n <= 9)
		counter += ft_putchar_pf(48 + n);
	else
	{
		counter += ft_putnbr_pf(n / 10);
		counter += ft_putchar_pf(48 + (n % 10));
	}
	return (counter);
}
