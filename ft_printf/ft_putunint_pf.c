/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunint_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:58:39 by marcogar          #+#    #+#             */
/*   Updated: 2023/05/30 21:22:43 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunint_pf(unsigned int n)
{
	int	counter;

	counter = 0;
	if (n > 0 && n <= 9)
		counter += ft_putchar_pf(48 + n);
	else
	{
		counter += ft_putunint_pf(n / 10);
		counter += ft_putchar_pf(48 + (n % 10));
	}
	return (counter);
}
