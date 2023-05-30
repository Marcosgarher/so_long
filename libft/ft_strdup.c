/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:45:41 by marcogar          #+#    #+#             */
/*   Updated: 2023/03/30 16:01:19 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*mem;

	len = ft_strlen(s1);
	if (!s1)
	{
		mem = ft_calloc(1, 1);
		ft_bzero(mem, 1);
		return (mem);
	}
	i = 0;
	mem = ft_calloc((len + 1), 1);
	if (!mem)
		return (NULL);
	while (i < len)
	{
		mem[i] = s1[i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
