/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:48:54 by marcogar          #+#    #+#             */
/*   Updated: 2023/06/05 11:50:54 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void ft_ini_vars(t_map_vars *data_map)
{
	data_map->c = 0;
	data_map->e = 0;
	data_map->p = 0;
	data_map->w = 0;
	data_map->f = 0;
}