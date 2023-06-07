/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:11:39 by marcogar          #+#    #+#             */
/*   Updated: 2023/06/07 14:12:15 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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