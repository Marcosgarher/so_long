/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:17:00 by marcogar          #+#    #+#             */
/*   Updated: 2023/06/08 16:13:25 by marcogar         ###   ########.fr       */
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

/* KEYS */
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_dataplus
{
	struct 	s_data 	*data;
	int		width;
	int		height;
	int		c;
	int		p;
	int		e;
	int		f;
	int		w;
	void	*mlx_win;
	int		width;
	int		height;
}			t_dataplus;


/* VALID MAP */
char		**ft_readmap(int fd);
void		ft_error(char *err);
int			ft_valid_file(char *name_map);
int			ft_check_map(char **map);
int			ft_valid_char(char c, t_map_vars *data_map);
void		ft_ini_vars(t_map_vars *data_map);
void		ft_check_sprites(t_map_vars *data_map);
int			ft_valid_map(char *name_map);
/* PRINT MAP */
void		ft_size_map(char **map, t_win *data_win);
void		ft_put_ground(void *mlx, t_win *data_win);
void		ft_select_img(void *mlx, char pointmap, t_data *img);
void		ft_put_others(void *mlx, t_win *data_win, char **map);
void		ft_open_win(t_win *data_win, char **map);
int			ft_print_map(char *name_map);
/* OTHERS */
void		ft_free_map(char **map);
int			ft_exit(int key, void *mlx);
int			ft_key_log(int key, void *mlx);

#endif
