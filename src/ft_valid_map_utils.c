/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:48:54 by marcogar          #+#    #+#             */
/*   Updated: 2023/06/05 15:29:16 by marcogar         ###   ########.fr       */
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

int	ft_valid_file(char *name_map)
{
	char	**rute;
	char	*ext;
	int		i;

	i = 0;
	rute = ft_split(name_map, '/');
	while (rute[i] && rute[i + 1])
		i++;
	if (ft_strrchr(rute[i], '.') != NULL)
	{
		ext = ft_strrchr(rute[i], '.');
		if (ft_strnstr(ext, ".ber", 4) != 0 && ft_strlen(ext) == 4)
			return (1);
	}
	return (0);
}