/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:37:47 by marcogar          #+#    #+#             */
/*   Updated: 2023/06/09 12:51:23 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_key_log(int key, t_info *info)
{
	if (key == KEY_W)
	{
		ft_up(info);
		printf("Arriba\n");
	}
	if (key == KEY_S)
	{
		ft_down(info);
		printf("Abajo\n");
	}
	if (key == KEY_A)
	{
		ft_left(info);
		printf("Izquierda\n");
	}
	if (key == KEY_D)
	{
		ft_right(info);
		printf("Derecha\n");
	}
	if (key == 53)
		ft_exit(key, info->mlx);
	return (1);
}

void	ft_up(t_info *info)
{
    if(info)
    {
        /*INFO*/
    }
}
void	ft_down(t_info *info)
{
    if(info)
    {
        /*INFO*/
    }
}
void	ft_left(t_info *info)
{
    if(info)
    {
        /*INFO*/
    }
}
void	ft_right(t_info *info)
{
    if(info)
    {
        /*INFO*/
    }
}
