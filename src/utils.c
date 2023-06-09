/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:51:21 by marcogar          #+#    #+#             */
/*   Updated: 2023/06/09 13:06:47 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void ft_free_map(t_info *info)
{
    int	i;

	i = 0;
	while (info->map[i] != 0)
	{
		free(info->map[i]);
		i++;
	}
	free(info->map);
}

void ft_free_rute(char **rute)
{
	int	i;

	i = 0;
	while (rute[i] != 0)
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
