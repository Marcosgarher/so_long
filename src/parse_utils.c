/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:03:45 by marcogar          #+#    #+#             */
/*   Updated: 2023/06/13 15:30:51 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int  valid_path_coins(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if(map[i][j] == 'C')
                return(0);
            ++j;
        }
        ++i;
    }
    return(1);
}

char	**find_path_coins(char **map, int x, int y)
{
    map[y][x] = ' ';
    if(map[y - 1][x] != '1' && map[y - 1][x] != ' ' && map[y - 1][x] != 'E')
        map = find_path_coins(map, x, (y - 1));
    if(map[y + 1][x] != '1' && map[y + 1][x] != ' '&& map[y + 1][x] != 'E')
        map = find_path_coins(map, x, (y + 1));
    if(map[y][x - 1] != '1' && map[y][x - 1] != ' ' && map[y][x - 1] != 'E')
        map = find_path_coins(map, (x - 1), y);
    if(map[y][x + 1] != '1' && map[y][x + 1] != ' ' && map[y][x + 1] != 'E')
        map = find_path_coins(map, (x + 1), y);
    return(map);
}
