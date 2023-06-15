/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:29:42 by marcogar          #+#    #+#             */
/*   Updated: 2023/06/15 08:40:38 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_info	*info;

	if (argc != 2)
		ft_perror("You must pass a map");
	if (argc == 2)
	{
		info = malloc(sizeof(t_info));
		if (!info)
			return (0);
		ft_ini_vars(info);
		ft_valid_map(argv[1], info);
		if (ft_print_map(argv[1], info))
			ft_error("Can not show the map", info);
		free(info);
	}
	return (0);
}
