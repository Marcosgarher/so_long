/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:04:13 by marcogar          #+#    #+#             */
/*   Updated: 2023/06/07 16:42:11 by marcogar         ###   ########.fr       */
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
	{
		free(data_map);
		ft_error("Caracter no valido");
	}
	return (0);
}
void	ft_check_sprites(t_map_vars *data_map)
{
	if (data_map->p <= 0 || data_map->p > 1)
	{
		free(data_map);
		ft_error("Falta o hay más de un personaje");
	}
	else if (data_map->c < 1)
	{
		free(data_map);
		ft_error("Faltan coleccionables");
	}
	else if (data_map->e <= 0 || data_map->e > 1)
	{
		free(data_map);
		ft_error("Falta o hay más de una salida");
	}
}

int	ft_check_map(char **map)
{
	int			i;
	int			j;
	t_map_vars	*data_map;

	if(!map)
		return(0);
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
			ft_valid_char(map[i][j], data_map);
			++j;
		}
		++i;
	}
	ft_check_sprites(data_map);
	return (1);
}

int	ft_valid_map(char *name_map)
{
	char	**map;
	int		fd;

	map = NULL;
	if (ft_valid_file(name_map))
	{
		fd = open(name_map, O_RDONLY);
		if (fd < 0)
			ft_error("Error al abrir el archivo");
		map = ft_readmap(fd);
		close(fd);
	}
	else
		ft_error("El mapa no es valido");
	ft_check_map(map);
	ft_free_map(map);
	return (0);
}
