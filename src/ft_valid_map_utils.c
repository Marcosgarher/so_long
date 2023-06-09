/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:48:54 by marcogar          #+#    #+#             */
/*   Updated: 2023/06/09 13:06:05 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void ft_ini_vars(t_info *info)
{
	info->mlx = NULL;
	info->mlx_win = NULL;
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
	info-> map = NULL;
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
		free(ext);
	}
	ft_free_rute(rute);
	return (0);
}
