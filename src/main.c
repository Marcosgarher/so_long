/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:29:42 by marcogar          #+#    #+#             */
/*   Updated: 2023/06/01 15:29:16 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_valid_char(char c, t_map_vars *data_map)
{
	if (c == 'P')
		data_map->p++;
	if (c == 'E')
		data_map->e++;
	if (c == 'C')
		data_map->c++;
}

int	ft_check_map(char **map)
{
	int			i;
	int			j;
	t_map_vars	*data_map;

	data_map = malloc(sizeof(t_map_vars));
	if(!data_map)
		return (0);
	data_map->c = 0;
	data_map->e = 0;
	data_map->p = 0;
	i = 0;
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
	printf("Personaje:%i\nColecionables:%i\nSalida:%i", data_map->p, data_map->c, data_map->e);
	return (0);
}

int	main(int argc, char *argv[])
{
	char	**map = NULL;
	int		fd;

	if (argc != 2)
		ft_error("Debes de pasa un mapa");
	if (ft_valid_file(argv[1]))
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			ft_error("Error al abrir el archivo");
		map = ft_readmap(fd);
		close(fd);
	}
	else
		ft_error("El mapa no es valido");
	ft_check_map(map);
	return (0);
}
