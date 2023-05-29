/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:28:47 by marcogar          #+#    #+#             */
/*   Updated: 2023/03/16 12:03:01 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*src;
	char	chr;

	src = (char *)s;
	i = ft_strlen(src);
	chr = (char)c;
	while (i >= 0)
	{
		if (chr == src[i])
			return (&src[i]);
		i--;
	}
	return (0);
}
