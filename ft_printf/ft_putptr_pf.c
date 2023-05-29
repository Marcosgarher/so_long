/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:56:51 by marcogar          #+#    #+#             */
/*   Updated: 2023/05/11 17:09:51 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa_ptr(unsigned long long hexa)
{
	int	counter;

	counter = 0;
	if (hexa >= 16)
	{
		counter += ft_puthexa_ptr(hexa / 16);
		counter += ft_puthexa_ptr(hexa % 16);
	}
	else
	{
		if (hexa <= 9)
			counter += ft_putchar_pf((hexa + 48));
		else
			counter += ft_putchar_pf(hexa - 10 + 'a');
	}
	return (counter);
}

int	ft_putptr_pf(unsigned long long ptr)
{
	int	counter;

	counter = 0;
	counter += write(1, "0x", 2);
	counter += ft_puthexa_ptr(ptr);
	return (counter);
}
