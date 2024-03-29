/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:51:21 by marcogar          #+#    #+#             */
/*   Updated: 2023/06/14 17:43:49 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free_map(t_info *info)
{
	int	i;

	i = 0;
	while (info->map[i] != NULL)
	{
		free(info->map[i]);
		i++;
	}
	free(info->map);
}

void	ft_free_rute(char **rute)
{
	int	i;

	i = 0;
	while (rute[i])
	{
		free(rute[i]);
		i++;
	}
	free(rute);
}

int	ft_exit(int key, t_info *info)
{
	if (key && info->mlx)
		exit(1);
	exit(1);
	return (1);
}

void	ft_serch_player(t_info *info)
{
	info->infop.y = 0;
	while (info->map[info->infop.y] != NULL)
	{
		info->infop.x = 0;
		while (info->map[info->infop.y][info->infop.x] != '\0'
			&& info->map[info->infop.y][info->infop.x] != 'P')
		{
			info->infop.x++;
		}
		if (info->map[info->infop.y][info->infop.x] == 'P')
			return ;
		info->infop.y++;
	}
}

void	ft_ini_vars(t_info *info)
{
	info->mlx = NULL;
	info->mlx_win = NULL;
	info->infop.movc = 0;
	info->img = NULL;
	info->imgw = 0;
	info->imgh = 0;
	info->coin = 0;
	info->exit = 0;
	info->player = 0;
	info->wall = 0;
	info->ground = 0;
	info->winw = 0;
	info->winh = 0;
	info->movements = 0;
	info->map = NULL;
}
