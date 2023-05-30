/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:53:02 by marcogar          #+#    #+#             */
/*   Updated: 2023/03/23 10:53:08 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*mem;
	size_t	i;
	int		j;

	if (!s || (start >= ft_strlen(s)))
	{
		mem = ft_calloc(1, sizeof(char));
		return (mem);
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	mem = ft_calloc((len + 1), sizeof(char));
	if (!mem)
		return (NULL);
	i = start;
	j = 0;
	while (s[i] != '\0' && i < (len + start))
	{
		mem[j] = s[i];
		i++;
		j++;
	}
	return (mem);
}
