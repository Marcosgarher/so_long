/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:29:42 by marcogar          #+#    #+#             */
/*   Updated: 2023/06/14 12:59:05 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_info	*info;

	if (argc != 2)
		ft_printf("\033[0;91mDebes de pasar un mapa\033[0m\n");
	if (argc == 2)
	{
		info = malloc(sizeof(t_info));
		if (!info)
			return (0);
		ft_ini_vars(info);
		ft_valid_map(argv[1], info);
		if (ft_print_map(argv[1], info))
			ft_error("Error al mostrar el mapa", info);
		free(info);
	}
	return (0);
}
