/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 09:12:02 by marcogar          #+#    #+#             */
/*   Updated: 2023/03/28 14:34:36 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*mem;

	if (!s || !f)
		return (0);
	mem = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!mem)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		mem[i] = f(i, s[i]);
		i++;
	}
	return (mem);
}
