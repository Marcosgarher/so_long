/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:19:24 by marcogar          #+#    #+#             */
/*   Updated: 2023/06/13 16:13:58 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error(char *err, t_info *info)
{
	ft_free_map(info);
	free(info);
	ft_printf("\033[0;91m%s\033[0m\n", err);
	exit(1);
}
