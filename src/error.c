/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:19:24 by marcogar          #+#    #+#             */
/*   Updated: 2023/06/15 08:42:34 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error(char *error, t_info *info)
{
	ft_free_map(info);
	free(info);
	ft_printf("\033[1;31mError\n\033[0m\033[4;31m%s\033[0m\n", error);
	exit(1);
}
void	ft_perror(char *error)
{
	ft_printf("\033[1;31mError\n\033[0m\033[4;31m%s\033[0m\n", error);
	exit(1);
}

void	ft_win(char *error, t_info *info)
{
	ft_free_map(info);
	free(info);
	ft_printf("\033[1;32m%s\033[0m\n", error);
	exit(1);
}
