/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:48:43 by marcogar          #+#    #+#             */
/*   Updated: 2023/03/28 11:37:03 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		i++;
	if (nb < 0)
	{
		nb = nb * -1;
		i++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*mem;
	int		i;
	int		len;

	len = ft_len(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	mem = ft_calloc(len + 1, sizeof(char));
	if (!mem)
		return (NULL);
	if (n < 0)
	{
		n = n * (-1);
		mem[0] = '-';
	}
	i = len - 1;
	while (i >= 0 && n != 0)
	{
		mem[i] = n % 10 + 48;
		n = n / 10;
		i--;
	}
	return (mem);
}
