/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:04:13 by marcogar          #+#    #+#             */
/*   Updated: 2023/05/31 12:48:55 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**ft_readmap(int fd)
{
	char	*line;
	char	*strmap;
	char	**map;

	strmap = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!(ft_strncmp(line, "(null)", ft_strlen(line))))
			break ;
		strmap = ft_strjoin(strmap, line);
		free(line);
	}
	map = ft_split(strmap, '\n');
	return (map);
}
int ft_valid_file(char *name_map)
{
	char **rute;
	char *ext;
	int	i;

	i = 0;
	rute = ft_split(name_map, '/');
	while (rute[i] && rute[i + 1])
		i++;
	ext = ft_strrchr(rute[i], '.');
	if (ft_strnstr(ext, ".ber", 4) != 0 && ft_strlen(ext) == 4)
		return(1);
	return(0);
}