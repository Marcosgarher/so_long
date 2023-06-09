/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:39:53 by marcogar          #+#    #+#             */
/*   Updated: 2023/06/09 14:40:12 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_size_map(char **map, t_info *info)
{
	if (!map)
		return ;
	info->winh = 0;
	while (map[info->winh])
	{
		info->winw = 0;
		while (map[info->winh][info->winw])
			info->winw++;
		info->winh++;
	}
}
void	ft_put_ground(t_info *info)
{
	int	imgwidth;
	int	imgheight;

	info->imgh = 0;
	info->data.img = mlx_xpm_file_to_image(info->mlx, "xpm/suelo.xpm",
			&imgwidth, &imgheight);
	while (info->imgh < info->winh)
	{
		info->imgw = 0;
		while (info->imgw < info->winw)
		{
			mlx_put_image_to_window(info->mlx, info->mlx_win, info->data.img,
					info->imgw * 64, info->imgh * 64);
			info->imgw++;
		}
		info->imgh++;
	}
}

void	ft_put_others(t_info *info)
{
	info->imgh = 0;
	while (info->imgh < info->winh)
	{
		info->imgw = 0;
		while (info->imgw < info->winw)
		{
			ft_select_img(info->map[info->imgh][info->imgw], info, (info->imgw + info->imgh));
			mlx_put_image_to_window(info->mlx, info->mlx_win, info->data.img, info->imgw * 64, info->imgh * 64);
			info->imgw++;
		}
		info->imgh++;
	}
}

void	ft_open_win(t_info *info)
{
	info->mlx = mlx_init();
	info->mlx_win = mlx_new_window(info->mlx, (info->winw) * 64, (info->winh)
			* 64, "So_long");
	ft_put_ground(info);
	ft_put_others(info);
	mlx_key_hook(info->mlx_win, ft_key_log, info);
	mlx_hook(info->mlx_win, 17, (1L << 17), ft_exit, info);
	mlx_loop(info->mlx);
}

int	ft_print_map(char *name_map, t_info *info)
{
	int	fd;

	fd = open(name_map, O_RDONLY);
	info->map = ft_readmap(fd);
	ft_size_map(info->map, info);
	ft_printf("Esto es el ancho: %i\nEsto es el alto: %i\n", info->winw,
			info->winh);
	ft_open_win(info);
	return (0);
}
