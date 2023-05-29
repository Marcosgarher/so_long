/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:05:51 by marcogar          #+#    #+#             */
/*   Updated: 2023/03/27 12:14:39 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_pfirst(char const *s1, char const *set)
{
	int	i;
	int	k;

	i = 0;
	while (s1[i] != '\0')
	{
		k = 0;
		while (set[k] != '\0' && s1[i] != '\0')
		{
			if (s1[i] == set[k])
			{
				k = 0;
				i++;
			}
			if (s1[i] != set[k])
				k++;
		}
		return (i);
	}
	return (0);
}

static int	ft_plast(char const *s1, char const *set)
{
	int	i;
	int	k;

	i = ft_strlen(s1) - 1;
	while (i > 0)
	{
		k = 0;
		while (set[k] != '\0' && i > 0)
		{
			if (s1[i] == set[k])
			{
				k = 0;
				i--;
			}
			if (s1[i] != set[k])
				k++;
		}
		return (i);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*mem;
	int		first;
	int		last;

	if (!s1 || !set)
		return (NULL);
	first = ft_pfirst(s1, set);
	last = ft_plast(s1, set);
	mem = ft_substr(s1, first, last - first + 1);
	return (mem);
}
