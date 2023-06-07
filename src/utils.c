/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:51:21 by marcogar          #+#    #+#             */
/*   Updated: 2023/06/07 16:43:19 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void ft_free_map(char **map)
{
    int	i;

	i = 0;
	while (map[i] != 0)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	ft_exit(int key, void *mlx)
{
	if (key && mlx)
		exit(1);
	exit(1);
	return (1);
}