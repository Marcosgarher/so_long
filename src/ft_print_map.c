/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:39:53 by marcogar          #+#    #+#             */
/*   Updated: 2023/06/06 12:42:40 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void ft_size_map(char **map, t_win *data_win)
{
    if(!map)
        return ;
	while(map[data_win->height])
	{
		data_win->width = 0;
		while(map[data_win->height][data_win->width])
			data_win->width++;
		data_win->height++;
	}
}
void ft_put_gound(void *mlx, t_win *data_win)
{
    t_data img;
    int imgwidth;
    int imgheight;

    img.img = mlx_xpm_file_to_image(mlx, "xpm/suelo.xpm", &imgwidth, &imgheight);
    while(( * 64) < ((data_win->height) * 64))
    {
        
    }
    
}
void ft_open_win(t_win *data_win)
{
    void *mlx;
    
    mlx = mlx_init();
    data_win->mlx_win = mlx_new_window(mlx, (data_win->width) * 64, (data_win->height) * 64, "So_long");
    ft_put_floor(mlx, data_win);
    mlx_loop(mlx);
}

int ft_print_map(char *name_map)
{
    int fd;
    char **map;
    t_win *data_win = NULL;
    
    fd = open(name_map, O_RDONLY);
    map = ft_readmap(fd);
    data_win = malloc(sizeof(t_win));
    if (!data_win)
        return(0);
    ft_memset(data_win, 0, sizeof(t_win));
    ft_size_map(map, data_win);
    ft_printf("Esto es el ancho: %i\nEsto es el alto: %i\n", data_win->width, data_win->height);
    ft_open_win(data_win);
    return (0);
} 
