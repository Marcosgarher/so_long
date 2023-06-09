/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:51:21 by marcogar          #+#    #+#             */
/*   Updated: 2023/06/09 17:34:00 by marcogar         ###   ########.fr       */
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
	while (rute[i] != NULL)
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
