/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:41:46 by marcogar          #+#    #+#             */
/*   Updated: 2023/05/29 17:20:22 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct {
    int x;
    int y;
} Character;

void move_character(Character *character, int keycode)
{
    // Actualizar la posición del personaje según la tecla presionada
    switch (keycode) {
        case 119:  // W
            character->y -= 1;  // Mover hacia arriba
            break;
        case 115:  // S
            character->y += 1;  // Mover hacia abajo
            break;
        case 97:   // A
            character->x -= 1;  // Mover hacia la izquierda
            break;
        case 100:  // D
            character->x += 1;  // Mover hacia la derecha
            break;
        default:
            break;
    }
}

int key_press_hook(int keycode, void *param)
{
    Character *character = (Character *)param;
    move_character(character, keycode);
    return 0;
}
int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	imagen;
	int		width;
	int		height;
    int     i;
    int     j;
	Character character;
	
	character.x = 0;
    character.y = 0;
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
	mlx_key_hook(mlx_win, key_press_hook, (void *)&character);
	mlx_put_image_to_window(mlx, mlx_win, imagen.img, (character.x * 64), (character.y * 64));
	mlx_loop(mlx);
}
