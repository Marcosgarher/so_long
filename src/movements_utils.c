/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:46:03 by marcogar          #+#    #+#             */
/*   Updated: 2023/06/12 14:53:48 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    ft_render(t_info *info, int x, int y, char c)
{
	ft_select_img(c, info);
	mlx_put_image_to_window(info->mlx, info->mlx_win, info->data.img,
			x * 64, y * 64);    
}