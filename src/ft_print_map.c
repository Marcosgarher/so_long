/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:39:53 by marcogar          #+#    #+#             */
/*   Updated: 2023/06/05 16:47:03 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void ft_size_map(char **map, t_win *data_win)
{
    data_win->height = 0;
    
	while (map[data_win->height] != NULL)
	{
		data_win->weight = 0;
		while (map[data_win->height][data_win->weight] != '\0')
			data_win->weight++;
		data_win->height++;
	}
    return ;
}

int ft_print_map(char *name_map)
{
    int fd;
    char **map;
    t_win *data_win;
    
    data_win = NULL;
    fd = open(name_map, O_RDONLY);
    map = ft_readmap(fd);
    ft_size_map(map, data_win);
    ft_printf("Esto es el ancho: %i\nEsto es el alto: %i\n", data_win->weight, data_win->height);
    return (0);
}