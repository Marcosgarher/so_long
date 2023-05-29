/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:58:48 by marcogar          #+#    #+#             */
/*   Updated: 2023/05/11 13:20:40 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_pf(char *str)
{
	int	counter;

	if (!str)
		str = "(null)";
	counter = 0;
	while (*str)
	{
		counter += ft_putchar_pf(*str);
		str++;
	}
	return (counter);
}
