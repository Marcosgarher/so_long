/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:29:42 by marcogar          #+#    #+#             */
/*   Updated: 2023/05/31 13:16:53 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// int	ft_valid_char(char c)
// {
	
// }
int	ft_check_map(char **map)
{
	int			i;
	t_map_vars	data_map;

	
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
	ft_printf("%s", map[1]);
	ft_check_map(map);
	return (0);
}
