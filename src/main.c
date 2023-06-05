/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:29:42 by marcogar          #+#    #+#             */
/*   Updated: 2023/06/05 15:41:32 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{	
	if (argc != 2)
		ft_error("Debes de pasar un mapa");
	if (argc == 2)
	{
		ft_valid_map(argv[1]);
		if (ft_print_map(argv[1]))
			ft_error("Error al mostrar el mapa");
	}
	return (0);
}
