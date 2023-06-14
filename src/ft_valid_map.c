/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:04:13 by marcogar          #+#    #+#             */
/*   Updated: 2023/06/14 17:11:39 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_readmap(int fd, t_info *info)
{
	char	*line;
	char	*strmap;

	strmap = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!(ft_strncmp(line, "(null)", ft_strlen(line))))
			break ;
		if(line[0] == '\n')
		{
			ft_perror("Invalid map");
			exit(1);
		}
		strmap = ft_strjoin(strmap, line);
		free(line);
	}
	info->map = ft_split(strmap, '\n');
	free(strmap);
}

int	ft_valid_char(char c, t_info *info)
{
	if (c == 'P')
		info->player++;
	else if (c == 'E')
		info->exit++;
	else if (c == 'C')
		info->coin++;
	else if (c == '1')
		info->wall++;
	else if (c == '0')
		info->ground++;
	else
		ft_error("Invalid character", info);
	return (0);
}

void	ft_check_sprites(t_info *info)
{
	if (info->player != 1)
		ft_error("Missing or there is more than one character", info);
	else if (info->coin < 1)
		ft_error("Missing collectables", info);
	else if (info->exit != 1)
		ft_error("Missing or there is more than one exit", info);
}

int	ft_check_map(t_info *info)
{
	int	i;
	int	j;

	if (!info->map)
		return (1);
	i = 0;
	while (info->map[i] != NULL)
	{
		j = 0;
		while (info->map[i][j] != '\0')
		{
			ft_valid_char(info->map[i][j], info);
			++j;
		}
		++i;
	}
	ft_check_sprites(info);
	return (0);
}

int	ft_valid_map(char *name_map, t_info *info)
{
	int	fd;

	if (ft_valid_file(name_map))
	{
		fd = open(name_map, O_RDONLY);
		if (fd <= 0)
		{
			ft_perror("Can't open the map");
			exit(1);
		}
		ft_readmap(fd, info);
		close(fd);
	}
	else
		ft_perror("Invalid map");
	if (ft_check_map(info))
		ft_perror("Invalid map");
	ft_is_rectangle(info);
	ft_check_border(info);
	parse(info); 
	ft_free_map(info);
	return (0);
}
