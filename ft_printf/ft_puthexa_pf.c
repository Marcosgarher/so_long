/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:56:17 by marcogar          #+#    #+#             */
/*   Updated: 2023/05/11 16:03:47 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa_pf(unsigned int hexa, char form)
{
	int	counter;

	counter = 0;
	if (hexa >= 16)
	{
		counter += ft_puthexa_pf(hexa / 16, form);
		counter += ft_puthexa_pf(hexa % 16, form);
	}
	else
	{
		if (hexa <= 9)
			counter += ft_putchar_pf((hexa + 48));
		else
		{
			if (form == 'x')
				counter += ft_putchar_pf(hexa - 10 + 'a');
			if (form == 'X')
				counter += ft_putchar_pf(hexa - 10 + 'A');
		}
	}
	return (counter);
}
