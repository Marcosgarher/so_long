/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:28:13 by marcogar          #+#    #+#             */
/*   Updated: 2023/06/01 13:29:07 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*src;
	char	chr;

	i = 0;
	src = (char *)s;
	chr = (char)c;
	while (src[i] != '\0')
	{
		if (chr == src[i])
			return (&src[i]);
		i++;
	}
	if (chr == '\0')
		return (&src[i]);
	return (0);
}
