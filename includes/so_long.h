/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:17:00 by marcogar          #+#    #+#             */
/*   Updated: 2023/06/06 12:42:01 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <limits.h>
# include <mlx.h>
# include <stdlib.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_map
{
	int		c;
	int		p;
	int		e;
	int		f;
	int		w;
}			t_map_vars;

typedef struct s_win
{
	void	*mlx_win;
	int		width;
	int		height;
}			t_win;

char		**ft_readmap(int fd);
void		ft_error(char *err);
int			ft_valid_file(char *name_map);
int			ft_check_map(char **map);
int			ft_valid_char(char c, t_map_vars *data_map);
void		ft_ini_vars(t_map_vars *data_map);
void		ft_check_sprites(t_map_vars *data_map);
int			ft_valid_map(char *name_map);
void		ft_size_map(char **map, t_win *data_win);
void		ft_put_gound(void *mlx, t_win *data_win);
void		ft_open_win(t_win *data_win);
int			ft_print_map(char *name_map);

#endif
