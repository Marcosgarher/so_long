/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:32:10 by marcogar          #+#    #+#             */
/*   Updated: 2023/03/17 17:21:17 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if ((unsigned char)s1[i] == '\0' && (unsigned char)s2[i] == '\0')
		return (0);
	while ((s1[i] != '\0' || s2[i] != '\0') && n > i)
	{
		if (((unsigned char)s1[i] < (unsigned char)s2[i]))
			return (-1);
		if (((unsigned char)s1[i] > (unsigned char)s2[i]))
			return (1);
		i++;
	}
	return (0);
}
