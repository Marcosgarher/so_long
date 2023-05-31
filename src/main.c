/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:29:42 by marcogar          #+#    #+#             */
/*   Updated: 2023/05/31 11:57:11 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_map(char **map)
{
	int i;
	int p;
	int c;
	int e;
	
	i = 0;
	p = 0;
	c = 0;
	e = 0;
	while(map[i] != NULL)
	{
		if (ft_strchr(map[i], 'P'))
			++p;
		if (ft_strchr(map[i], 'C'))
			++c;
		if (ft_strchr(map[i], 'E'))
			++e;
		++i;
	}
}

int	main(int argc, char *argv[])
{
	char **map;
	int fd;
	
	if (argc != 2)
		ft_error("Debes de pasa un mapa");
	if (ft_validmap(argv[1]))
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
