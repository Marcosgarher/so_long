/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:42:31 by marcogar          #+#    #+#             */
/*   Updated: 2023/03/17 15:56:13 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (((unsigned char)str1[i] < (unsigned char)str2[i]))
			return (str1[i] - str2[i]);
		if (((unsigned char)str1[i] > (unsigned char)str2[i]))
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
