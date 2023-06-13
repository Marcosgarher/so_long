/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:32:05 by marcogar          #+#    #+#             */
/*   Updated: 2023/06/13 13:22:29 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int  valid_path(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if(map[i][j] == 'C' || map[i][j] == 'E')
                return(0);
            ++j;
        }
        ++i;
    }
    return(1);
}

char	**find_path(char **map, int x, int y)
{
    map[y][x] = '.';
    if(map[y - 1][x] != '1' && map[y - 1][x] != '.')
        map = find_path(map, x, (y - 1));
    if(map[y + 1][x] != '1' && map[y + 1][x] != '.')
        map = find_path(map, x, (y + 1));
    if(map[y][x - 1] != '1' && map[y][x - 1] != '.')
        map = find_path(map, (x - 1), y);
    if(map[y][x + 1] != '1' && map[y][x + 1] != '.')
        map = find_path(map, (x + 1), y);
    return(map);
}

void	parse(t_info *info)
{
    char **copy_map;

    copy_map = ft_copy_map(info);
    ft_serch_player(info);
    copy_map = find_path(copy_map, info->infop.x, info->infop.y);
    if (!valid_path(copy_map))
    {
        ft_free_rute(copy_map);
        ft_error("No hay un camino valido");
    }
    ft_free_rute(copy_map);
}


char **ft_copy_map(t_info *info)
{
	char	**copy;
	int		i;

    i = 0;
    while(info->map[i])
        ++i;
	copy = (char **)malloc((i + 1) * sizeof(char *));
    if(!copy)
        return(NULL);
    i = 0;
    while(info->map[i])
    {
        copy[i] = ft_strdup(info->map[i]);
        ++i;
    }
    copy[i] = 0;
    return(copy);
}


