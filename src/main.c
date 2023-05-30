/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:29:42 by marcogar          #+#    #+#             */
/*   Updated: 2023/05/30 21:22:18 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int ft_validmap(char *name_map)
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

int	main(int argc, char *argv[])
{
	//char **map;
	int fd;
	
	if (argc != 2)
		ft_error("Debes de pasa un mapa");
	if (ft_validmap(argv[1]))
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			ft_error("Error al abrir el archivo");
		//map = ft_readmap(fd);
		close(fd);
	}
	else
		ft_error("El mapa no es valido");
	return (0);
}
