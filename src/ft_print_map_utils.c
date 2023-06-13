/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:11:39 by marcogar          #+#    #+#             */
/*   Updated: 2023/06/13 15:46:28 by marcogar         ###   ########.fr       */
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
		return (NULL);
	return (img);
}

void	ft_select_img(char pointmap, t_info *info)
{
	if (pointmap == '1')
		info->data.img = create_image(info->mlx, "xpm/pared.xpm");
	if (pointmap == 'P')
		info->data.img = create_image(info->mlx, "xpm/dino.xpm");
	if (pointmap == 'E')
		info->data.img = create_image(info->mlx, "xpm/portal.xpm");
	if (pointmap == 'C')
		info->data.img = create_image(info->mlx, "xpm/pata.xpm");
	if (pointmap == '0')
		info->data.img = create_image(info->mlx, "xpm/suelo.xpm");
	return ;
}
