/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:37:47 by marcogar          #+#    #+#             */
/*   Updated: 2023/06/09 12:03:25 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int ft_key_log(int key, t_info *info)
{
	if(info->mlx)
	{/*TODO*/}
	if(key == KEY_W)
    {
        ft_up();
		printf("Arriba\n");
    }
	if(key == KEY_S)
	{
        ft_down();
		printf("Abajo\n");
    }
	if(key == KEY_A)
	{
        ft_left();
		printf("Izquierda\n");
    }
	if(key == KEY_D)
	{
        ft_right();
		printf("Derecha\n");
    }
	if (key == 53)
		ft_exit(key, info->mlx);
	return(1);
}

