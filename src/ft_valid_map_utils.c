/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:48:54 by marcogar          #+#    #+#             */
/*   Updated: 2023/06/14 16:56:26 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
		{
			ft_free_rute(rute);
			return (1);
		}
	}
	ft_free_rute(rute);
	return (0);
}

void	ft_is_rectangle(t_info *info)
{
	int	i;

	i = 0;
	while (info->map[i + 1])
	{
		if (ft_strlen(info->map[i]) != ft_strlen(info->map[i + 1]))
			ft_error("The map is not a rectangle", info);
		++i;
	}
}

void	ft_check_border(t_info *info)
{
	int	x;
	int	y;
	int	len;

	len = ft_strlen(info->map[0]);
	y = 0;
	x = 0;
	while (info->map[0][x])
	{
		if (info->map[0][x++] != '1')
			ft_error("The map is not close", info);
	}
	while (info->map[y + 1])
	{
		if (info->map[y][0] != '1' || info->map[y][len - 1] != '1')
			ft_error("The map is not close", info);
		++y;
	}
	x = 0;
	while (info->map[y][x])
	{
		if (info->map[y][x++] != '1')
			ft_error("The map is not close", info);
	}
}
