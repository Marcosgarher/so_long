/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:29:42 by marcogar          #+#    #+#             */
/*   Updated: 2023/06/09 10:53:10 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void ft_leaks(void)
{
	system("leaks so_long");
}

int	main(int argc, char *argv[])
{	
	t_info *info;
	//atexit(ft_leaks);
	if (argc != 2)
		ft_error("Debes de pasar un mapa");
	if (argc == 2)
	{
		info = malloc(sizeof(t_info));
		if(!info)
			return(0);
		ft_ini_vars(info);
		ft_valid_map(argv[1], info);
		if (ft_print_map(argv[1], info))
			ft_error("Error al mostrar el mapa");
	}
	return (0);
}
