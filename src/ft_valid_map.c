/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:04:13 by marcogar          #+#    #+#             */
/*   Updated: 2023/06/05 10:13:19 by marcogar         ###   ########.fr       */
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
int	ft_valid_file(char *name_map)
{
	char	**rute;
	char	*ext;
	int		i;

	i = 0;
	rute = ft_split(name_map, '/');
	while (rute[i] && rute[i + 1])
		i++;
	if (ft_strrchr(rute[i], '.') != NULL)
	{
		ext = ft_strrchr(rute[i], '.');
		if (ft_strnstr(ext, ".ber", 4) != 0 && ft_strlen(ext) == 4)
			return (1);
	}
	return (0);
}

int	ft_valid_char(char c, t_map_vars *data_map)
{
	if (c == 'P')
		data_map->p++;
	else if (c == 'E')
		data_map->e++;
	else if (c == 'C')
		data_map->c++;
	else if (c == '1')
		data_map->w++;
	else if (c == '0')
		data_map->f++;
	else
		ft_error("Caracter no valido");
		
	return (0);
}

int	ft_check_map(char **map)
{
	int			i;
	int			j;
	t_map_vars	*data_map;

	data_map = malloc(sizeof(t_map_vars));
	if (!data_map)
		return (0);
	i = 0;
	ft_ini_vars(data_map);
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (ft_valid_char(map[i][j], data_map))
				return(0);
			++j;
		}
		++i;
	}
	return (1);
}

void ft_ini_vars(t_map_vars *data_map)
{
	data_map->c = 0;
	data_map->e = 0;
	data_map->p = 0;
	data_map->w = 0;
	data_map->f = 0;
}