/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 18:04:15 by bbrunet           #+#    #+#             */
/*   Updated: 2019/12/03 14:49:20 by bbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PRINTF_H_
# define _PRINTF_H_

#include <stdio.h>
#include <stdarg.h>

int		ft_printf(const char *format, ...);
int		print_arg(va_list ap, const char id, int flag, int width, int prec);

#endif
