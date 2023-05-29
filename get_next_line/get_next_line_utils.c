/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 09:44:55 by marcogar          #+#    #+#             */
/*   Updated: 2023/04/21 12:51:55 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strchr_gnl(char *s, int c)
{
	int		i;
	char	chr;

	if (!s)
		return (0);
	i = 0;
	chr = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*mem;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	mem = malloc((ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1) * sizeof(char));
	mem[(ft_strlen_gnl(s1) + ft_strlen_gnl(s2))] = '\0';
	if (!mem)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		mem[i] = s1[i];
	j = 0;
	while (s2[j] != '\0')
		mem[i++] = s2[j++];
	mem[i] = '\0';
	free(s1);
	return (mem);
}
