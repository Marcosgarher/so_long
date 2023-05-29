/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunint_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:58:39 by marcogar          #+#    #+#             */
/*   Updated: 2023/05/11 16:19:33 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunint_pf(unsigned int n)
{
	int	counter;

	counter = 0;
	if (n >= 0 && n <= 9)
		counter += ft_putchar_pf(48 + n);
	else
	{
		counter += ft_putunint_pf(n / 10);
		counter += ft_putchar_pf(48 + (n % 10));
	}
	return (counter);
}
