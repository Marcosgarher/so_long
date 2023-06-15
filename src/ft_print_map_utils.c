/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:11:39 by marcogar          #+#    #+#             */
/*   Updated: 2023/06/15 08:57:23 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*create_image(void *mlx, char *path)
{
	int			imgwidth;
	int			imgheight;
	void		*img;

	img = mlx_xpm_file_to_image(mlx, path, &imgwidth, &imgheight);
	if (img == NULL)
		ft_perror("Failed to load image");
	return (img);
}

void	ft_select_img(char pointmap, t_info *info)
{
	if (pointmap == '1')
		info->img = create_image(info->mlx, "textures/pared.xpm");
	if (pointmap == 'P')
		info->img = create_image(info->mlx, "textures/dino.xpm");
	if (pointmap == 'E')
		info->img = create_image(info->mlx, "textures/portal.xpm");
	if (pointmap == 'C')
		info->img = create_image(info->mlx, "textures/pata.xpm");
	if (pointmap == '0')
		info->img = create_image(info->mlx, "textures/suelo.xpm");
	return ;
}
