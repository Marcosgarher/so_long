/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:37:47 by marcogar          #+#    #+#             */
/*   Updated: 2023/06/12 09:32:55 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_key_log(int key, t_info *info)
{
	if (key == 53)
		ft_exit(key, info->mlx);
	ft_serch_player(info);
	if (key == KEY_W)
		ft_up(info);
	if (key == KEY_S)
		ft_down(info);
	if (key == KEY_A)
		ft_left(info);
	if (key == KEY_D)
		ft_right(info);
	return (1);
}

void	ft_up(t_info *info)
{
	if (info->map[info->infop.y - 1][info->infop.x] != '1')
	{
		if (info->map[info->infop.y - 1][info->infop.x] == 'C')
			info->coin--;
		if (info->map[info->infop.y - 1][info->infop.x] != 'E')
		{
			info->map[info->infop.y][info->infop.x] = '0';
			info->map[info->infop.y - 1][info->infop.x] = 'P';
			info->infop.y--;
			info->infop.movc++;
			ft_printf("Movements: %i\n", info->infop.movc);
		}
		else if (info->map[info->infop.y - 1][info->infop.x] == 'E'
				&& info->coin == 0)
			ft_error("YOU WIN!!");
		ft_put_ground(info);
		ft_put_others(info);
	}
}

void	ft_down(t_info *info)
{
	if (info->map[info->infop.y + 1][info->infop.x] != '1')
	{
		if (info->map[info->infop.y + 1][info->infop.x] == 'C')
			info->coin--;
		if (info->map[info->infop.y + 1][info->infop.x] != 'E')
		{
			info->map[info->infop.y][info->infop.x] = '0';
			info->map[info->infop.y + 1][info->infop.x] = 'P';
			info->infop.y++;
			info->infop.movc++;
			ft_printf("Movements: %i\n", info->infop.movc);
		}
		else if (info->map[info->infop.y + 1][info->infop.x] == 'E'
				&& info->coin == 0)
			ft_error("YOU WIN!!");
		ft_put_ground(info);
		ft_put_others(info);
	}
}

void	ft_left(t_info *info)
{
	if (info->map[info->infop.y][info->infop.x - 1] != '1')
	{
		if (info->map[info->infop.y][info->infop.x - 1] == 'C')
			info->coin--;
		if (info->map[info->infop.y][info->infop.x - 1] != 'E')
		{
			info->map[info->infop.y][info->infop.x] = '0';
			info->map[info->infop.y][info->infop.x - 1] = 'P';
			info->infop.x--;
			info->infop.movc++;
			ft_printf("Movements: %i\n", info->infop.movc);
		}
		else if (info->map[info->infop.y][info->infop.x - 1] == 'E'
				&& info->coin == 0)
			ft_error("YOU WIN!!");
		ft_put_ground(info);
		ft_put_others(info);
	}
}

void	ft_right(t_info *info)
{
	if (info->map[info->infop.y][info->infop.x + 1] != '1')
	{
		if (info->map[info->infop.y][info->infop.x + 1] == 'C')
			info->coin--;
		if (info->map[info->infop.y][info->infop.x + 1] != 'E')
		{
			info->map[info->infop.y][info->infop.x] = '0';
			info->map[info->infop.y][info->infop.x + 1] = 'P';
			info->infop.x++;
			info->infop.movc++;
			ft_printf("Movements: %i\n", info->infop.movc);
		}
		else if (info->map[info->infop.y][info->infop.x + 1] == 'E'
				&& info->coin == 0)
			ft_error("YOU WIN!!");
		ft_put_ground(info);
		ft_put_others(info);
	}
}
