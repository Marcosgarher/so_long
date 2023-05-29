/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcogar <marcogar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:14:10 by marcogar          #+#    #+#             */
/*   Updated: 2023/05/11 17:12:44 by marcogar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putchar_pf(char c);
int	ft_putnbr_pf(int n);
int	ft_putstr_pf(char *str);
int	ft_puthexa_pf(unsigned int hexa, char form);
int	ft_puthexa_ptr(unsigned long long hexa);
int	ft_putptr_pf(unsigned long long ptr);
int	ft_putunint_pf(unsigned int n);
int	ft_format(char *format, va_list arguments);
int	ft_printf(char const *format, ...);

#endif
