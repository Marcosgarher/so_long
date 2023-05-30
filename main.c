/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:29:42 by marcogar          #+#    #+#             */
/*   Updated: 2023/05/30 14:00:50 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **ft_readmap(int fd)
{
	char	*line;
	char	*strmap = NULL;
	char	**map;

	
	while (1)
	{
		line = get_next_line(fd);
		if (!(ft_strncmp(line, "(null)", ft_strlen(line))))
			break ;
		strmap = ft_strjoin(strmap, line);
		free(line);
	}
	map = ft_split(strmap, '\n');
    return(map);
}
int	main(int argc, char *argv[])
{
	char **map;
	int fd;
	
	if (argc == 2)
	{
		ft_validmap(argv[1]);
		fd = open(argv[1], O_RDONLY);
		map = ft_readmap(fd);
		while (*map != NULL)
		{
			ft_printf("%s\n", *map);
			map++;
		}
		close(fd);
	}
	return (0);
}
