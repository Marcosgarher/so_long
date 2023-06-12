/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:17:00 by marcogar          #+#    #+#             */
/*   Updated: 2023/06/12 10:44:08 by marcogar         ###   ########.fr       */
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
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

/* STRUCTS */

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_player
{
	int			x;
	int			y;
	int			movc;
}				t_player;

typedef struct s_info
{
	t_data		data;
	t_player	infop;
	void		*mlx;
	void		*mlx_win;
	int			imgw;
	int			imgh;
	int			coin;
	int			player;
	int			exit;
	int			ground;
	int			wall;
	int			winw;
	int			winh;
	int			movements;
	char		**map;
}				t_info;

/* VALID MAP */

void			ft_readmap(int fd, t_info *info);
void			ft_error(char *err);
int				ft_valid_file(char *name_map);
int				ft_check_map(t_info *info);
int				ft_valid_char(char c, t_info *info);
void			ft_ini_vars(t_info *info);
void			ft_check_sprites(t_info *info);
//void			ft_is_rectangle(t_info *info);
int				ft_valid_map(char *name_map, t_info *info);

/* PRINT MAP */

void			ft_size_map(char **map, t_info *info);
void			ft_put_ground(t_info *info);
void			ft_select_img(char pointmap, t_info *info);
void			ft_put_others(t_info *info);
void			ft_open_win(t_info *info);
int				ft_print_map(char *name_map, t_info *info);

/* MOVEMENTS */

void			ft_up(t_info *info);
void			ft_down(t_info *info);
void			ft_left(t_info *info);
void			ft_right(t_info *info);
int				ft_key_log(int key, t_info *info);

/* OTHERS */

void			ft_free_map(t_info *info);
void			ft_free_rute(char **rute);
int				ft_exit(int key, t_info *info);
void			ft_serch_player(t_info *info);
void			ft_leaks(void);

#endif
