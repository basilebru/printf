/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 18:04:15 by bbrunet           #+#    #+#             */
/*   Updated: 2019/12/05 18:20:20 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PRINTF_H_
# define _PRINTF_H_

#include <stdio.h>
#include <stdarg.h>

int		ft_printf(const char *format, ...);
int		print_arg(va_list ap, const char id, int flag, int width, int prec);
int		ft_arg_int(int n, const char id, int flag, int width, int prec);
int		ft_add_zeros(char **nbr, int add_num, int len_nbr);
void	ft_fill_field(char **nbr, const char *tmp, int flag, int add_num);
int		ft_set_field(char **nbr, int flag, int add_num, int len_nbr);
int		ft_arg_uint(unsigned int n, const char id, int flag, int width, int prec);
int		ft_arg_str(const char *str, int flag, int width, int prec);

	
#endif
