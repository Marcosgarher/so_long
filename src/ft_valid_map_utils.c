/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:48:54 by marcogar          #+#    #+#             */
/*   Updated: 2023/06/12 10:53:45 by marcogar         ###   ########.fr       */
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
	return (0);
}
// void ft_is_rectangle(t_info *info)
// {
// 	char **rtg;
// 	int i;
// 	int j;
// 	int max;
	
// 	i = 0;
// 	rtg = info->map;
// 	while(rtg[i])
// 	{
// 		j = 0;
// 		while(rtg[i][j])
// 			++j;
// 		if ()
// 		++i;
// 	}
// }