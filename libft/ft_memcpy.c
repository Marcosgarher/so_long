/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:29:13 by marcogar          #+#    #+#             */
/*   Updated: 2023/03/17 16:03:28 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*auxf;
	const unsigned char	*auxs;

	auxf = (unsigned char *)dst;
	auxs = (unsigned char *)src;
	if (!auxf && !auxs)
		return (0);
	while (n-- > 0)
		*(auxf++) = *(auxs++);
	return (dst);
}
