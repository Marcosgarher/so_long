/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:51:21 by marcogar          #+#    #+#             */
/*   Updated: 2023/06/08 15:38:34 by marcogar         ###   ########.fr       */
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

int ft_key_log(int key, void *mlx, void *mlx_win)
{
	if(mlx)
	{/*TODO*/}
	if(key == KEY_UP ||  key == KEY_W)
		printf("Arriba\n");
	if(key == KEY_DOWN ||  key == KEY_S)
		printf("Abajo\n");
	if(key == KEY_LEFT ||  key == KEY_A)
		printf("Izquierda\n");
	if(key == KEY_RIGHT ||  key == KEY_D)
		printf("Derecha\n");
	if (key == 53)
		ft_exit(key, mlx);
	return(1);
}
