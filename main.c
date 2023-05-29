/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:41:46 by marcogar          #+#    #+#             */
/*   Updated: 2023/05/25 15:48:40 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	imagen;
	int		width;
	int		height;
    int     i;
    int     j;

    i = 0;
    j = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 640, 640, "42 Madrid");
	imagen.img = mlx_xpm_file_to_image(mlx, "xpm/suelo.xpm", &width, &height);
    while((i * 64) < 640)
    {
		j = 0;
		while((j * 64) < 640)
		{
        	mlx_put_image_to_window(mlx, mlx_win, imagen.img, (i * 64), (j * 64));
        	j++;
		}  
        i++;
    }
	imagen.img = mlx_xpm_file_to_image(mlx, "xpm/pared.xpm", &width, &height);
	j = 0;
	while((j * 64) < 640)
	{
        mlx_put_image_to_window(mlx, mlx_win, imagen.img, j * 64 ,0);
        j++;
	}
	imagen.img = mlx_xpm_file_to_image(mlx, "xpm/dino.xpm", &width, &height);
	mlx_put_image_to_window(mlx, mlx_win, imagen.img, 64, 64);
	imagen.img = mlx_xpm_file_to_image(mlx, "xpm/arbusto.xpm", &width, &height);
	mlx_put_image_to_window(mlx, mlx_win, imagen.img, 0, 64);
	imagen.img = mlx_xpm_file_to_image(mlx, "xpm/pata.xpm", &width, &height);
	mlx_put_image_to_window(mlx, mlx_win, imagen.img, 128, 64);
	imagen.img = mlx_xpm_file_to_image(mlx, "xpm/portal.xpm", &width, &height);
	mlx_put_image_to_window(mlx, mlx_win, imagen.img, 192, 64);
	mlx_loop(mlx);
}
