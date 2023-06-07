/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:39:53 by marcogar          #+#    #+#             */
/*   Updated: 2023/06/07 14:02:35 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_size_map(char **map, t_win *data_win)
{
	if (!map)
		return ;
	while (map[data_win->height])
	{
		data_win->width = 0;
		while (map[data_win->height][data_win->width])
			data_win->width++;
		data_win->height++;
	}
}
void	ft_put_ground(void *mlx, t_win *data_win)
{
	t_data		img;
	t_imgplus	imgplus;
	int			imgwidth;
	int			imgheight;

	imgplus.height = 0;
	img.img = mlx_xpm_file_to_image(mlx, "xpm/suelo.xpm", &imgwidth,
			&imgheight);
	while (imgplus.height < data_win->height)
	{
		imgplus.width = 0;
		while (imgplus.width < data_win->width)
		{
			mlx_put_image_to_window(mlx, data_win->mlx_win, img.img,
				imgplus.width * 64, imgplus.height * 64);
			imgplus.width++;
		}
		imgplus.height++;
	}
}
void ft_select_img(void *mlx, char pointmap, t_data *img)
{
	int			imgwidth;
	int			imgheight;
	
	if(pointmap == '1')
		img->img = mlx_xpm_file_to_image(mlx, "xpm/pared.xpm", &imgwidth, &imgheight);
	if(pointmap == 'P')
		img->img = mlx_xpm_file_to_image(mlx, "xpm/dino.xpm", &imgwidth, &imgheight);
	if(pointmap == 'E')
		img->img = mlx_xpm_file_to_image(mlx, "xpm/portal.xpm", &imgwidth, &imgheight);
	if(pointmap == 'C')
		img->img = mlx_xpm_file_to_image(mlx, "xpm/pata.xpm", &imgwidth, &imgheight);
	if(pointmap == '0')
		img->img = mlx_xpm_file_to_image(mlx, "xpm/suelo.xpm", &imgwidth, &imgheight);
	return ;
}

void ft_put_others(void *mlx, t_win *data_win, char **map)
{
	t_data		*img;
	t_imgplus	imgplus;
	
	img = malloc(sizeof(t_data));
	if(!img)
		return ;
	imgplus.height = 0;
	while(imgplus.height < data_win->height)
	{
		imgplus.width = 0;
			while(imgplus.width < data_win->width)
			{
				printf("a\n");
				ft_select_img(mlx, map[imgplus.height][imgplus.width], img);
				printf("b\n");
				mlx_put_image_to_window(mlx, data_win->mlx_win, img->img, imgplus.width * 64, imgplus.height * 64);
				imgplus.width++;
			}
		imgplus.height++;
	}
	free(img);
}

void	ft_open_win(t_win *data_win, char **map)
{
	void	*mlx;

	mlx = mlx_init();
	data_win->mlx_win = mlx_new_window(mlx, (data_win->width) * 64,
			(data_win->height) * 64, "So_long");
	ft_put_ground(mlx, data_win);
	ft_put_others(mlx, data_win, map);
	mlx_loop(mlx);
}

int	ft_print_map(char *name_map)
{
	int		fd;
	char	**map;
	t_win	*data_win;

	data_win = NULL;
	fd = open(name_map, O_RDONLY);
	map = ft_readmap(fd);
	data_win = malloc(sizeof(t_win));
	if (!data_win)
		return (0);
	ft_memset(data_win, 0, sizeof(t_win));
	ft_size_map(map, data_win);
	ft_printf("Esto es el ancho: %i\nEsto es el alto: %i\n", data_win->width,
		data_win->height);
	ft_open_win(data_win, map);
	return (0);
}
