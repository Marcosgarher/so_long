/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:53:01 by marcogar          #+#    #+#             */
/*   Updated: 2023/03/21 17:14:28 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_d;
	size_t	len_s;
	size_t	i;

	if (dstsize == 0 && (!dst || !src))
		return (0);
	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	if (dstsize != 0)
	{
		if (dstsize <= len_d)
			len_s += dstsize;
		else
			len_s += len_d;
		i = 0;
		while (src[i] != '\0' && len_d < (dstsize - 1))
		{
			dst[len_d] = src[i];
			i++;
			len_d++;
		}
		dst[len_d] = '\0';
	}
	return (len_s);
}
