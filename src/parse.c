/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:32:05 by marcogar          #+#    #+#             */
/*   Updated: 2023/06/13 10:48:44 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**find_path(char **map, int x, int y)
{
    map[y][x]
}

void	parse(t_info *info)
{
    char **copy_map;

    copy_map = ft_copy_map(info);
    find_path(copy_map, info->infop.x, info->infop.y);
}

// void ft_print(char **map)
// {
//     int i;
    
//     i = 0;
//     while(map[i])
//     {
//         ft_printf("%s\n", map[i]);
//         ++i;
//     }
// }

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


